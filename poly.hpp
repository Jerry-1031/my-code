#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 998244353;
const int inv2 = (mod + 1) / 2;

inline int qpow(int a_, int n_)
{
	int r = 1;
	for(; n_; n_ >>= 1, a_ = 1ll * a_ * a_ % mod)
		if(n_ & 1) r = 1ll * r * a_ % mod;
	return r;
}

namespace polynomial
{
	const int N = 1 << 20, LG = 21;
	int w[N + 5], inv_[N + 5], g[N + 5];
	void init()
	{
		w[0] = 1, w[N] = qpow(3, (mod - 1) >> (LG + 1));
		for(int i = LG - 1; i; i--)
			w[1 << (i - 1)] = 1ll * w[1 << i] * w[1 << i] % mod;
		for(int i = 1; i <= N; i++)
			w[i] = 1ll * w[i & (i - 1)] * w[i & -i] % mod;
		inv_[1] = 1;
		for(int i = 2; i <= N; i++)
			inv_[i] = 1ll * inv_[mod % i] * (mod - mod / i) % mod;
	}
	struct Poly
	{
		vector<int> a;
		int S;

		inline int size() const { return a.size(); }
		inline int& operator [] (const int &x) { return a[x]; }
		inline void clear() { a.clear(); a.shrink_to_fit(); }
		inline void resize(const int &x) { a.resize(S = x); }

		Poly(int n = 0) { resize(S = n); }
		Poly(const vector<int> &v) { a = v; S = v.size(); }

		friend Poly operator + (Poly a, Poly b)
		{
			int s = max(a.size(), b.size());
			a.resize(s);
			b.resize(s);
			for(int i = 0; i < s; i++)
				(a[i] += b[i]) %= mod;
			return a;
		}
		friend Poly operator - (Poly a, Poly b)
		{
			int s = max(a.size(), b.size());
			a.resize(s);
			b.resize(s);
			for(int i = 0; i < s; i++)
				(a[i] += mod - b[i]) %= mod;
			return a;
		}

		void DIF()
		{
			for(int p = S >> 1; p; p >>= 1)
				for(int *tg = g, *tw = w; tg != g + S; tg += p << 1, tw++)
					for(int *pg = tg; pg != tg + p; pg++)
					{
						int s = 1ll * pg[p] * *tw % mod;
						pg[p] = (*pg - s + mod) % mod;
						(*pg += s) %= mod;
					}
		}
		void DIT()
		{
			for(int p = 1; p < S; p <<= 1)
				for(int *tg = g, *tw = w; tg != g + S; tg += p << 1, tw++)
					for(int *pg = tg; pg != tg + p; pg++)
					{
						int s = pg[p];
						pg[p] = 1ll * (*pg - s + mod) * *tw % mod;
						(*pg += s) %= mod;
					}
		}
		void DFT()
		{
			copy_n(a.begin(), S, g);
			DIF();
			for(int i = 0; i < S; i++)
				a[i] = g[i];
		}
		void IDFT()
		{
			copy_n(a.begin(), S, g);
			DIT();
			for(int i = 0, iv = mod - (mod - 1) / S; i < S; i++)
				a[i] = 1ll * g[i] * iv % mod;
			reverse(++a.begin(), a.end());
		}
		friend Poly operator * (Poly a, Poly b)
		{
			int n = a.size(), m = b.size(), s = 1;
			while(s < n + m - 1)
				s <<= 1;
			a.resize(s);
			a.DFT();
			b.resize(s);
			b.DFT();
			for(int i = 0; i < s; i++)
				a[i] = 1ll * a[i] * b[i] % mod;
			a.IDFT();
			a.resize(n + m - 1);
			return a;
		}
		Poly inv()
		{
			Poly b(1), c;
			b[0] = qpow(a[0], mod - 2);
			for(int i = 1; i < S; i <<= 1)
			{
				c = a;
				c.resize(i << 1);
				c.resize(i << 2);
				c.DFT();
				b.resize(i << 2);
				b.DFT();
				for(int j = 0; j < i << 2; j++)
					b[j] = 1ll * b[j] * (2 - 1ll * b[j] * c[j] % mod + mod) % mod;
				b.IDFT();
				b.resize(i << 1);
			}
			b.resize(S);
			return b;
		}
		inline Poly deriv()
		{
			Poly b(S - 1);
			for(int i = 1; i < S; i++)
				b[i - 1] = 1ll * a[i] * i % mod;
			return b;
		}
		inline Poly inter()
		{
			Poly b(S + 1);
			for(int i = 0; i < S; i++)
				b[i + 1] = 1ll * a[i] * inv_[i + 1] % mod;
			return b;
		}
		Poly ln()
		{
			Poly b = (deriv() * inv()).inter();
			b.resize(S);
			return b;
		}
		Poly exp()
		{
			Poly b(1), c;
			b[0] = 1;
			for(int i = 1; i < S; i <<= 1)
			{
				c = b;
				c.resize(i << 1);
				c = c.ln();
				for(int j = 0; j < min(S, i << 1); j++)
					c[j] = (c[j] - a[j] - !j + mod) % mod;
				for(int j = 0; j < i << 1; j++)
					c[j] = mod - c[j];
				b = b * c;
			}
			b.resize(S);
			return b;
		}
		Poly pow(int k)
		{
			Poly b = ln();
			for(int i = 0; i < S; i++)
				b[i] = 1ll * b[i] * k % mod;
			return b.exp();
		}
		Poly sqrt()
		{
			Poly b(1), c, d;
			b[0] = 1;
			for(int i = 1; i < S; i <<= 1)
			{
				b.resize(i << 1);
				d = a;
				d.resize(i << 1);
				c = b.inv() * d;
				for(int j = 0; j < i << 1; j++)
					b[i] = 1ll * (b[j] + c[j]) * inv2 % mod;
			}
			b.resize(S);
			return b;
		}
	};
}

using polynomial::init;
using polynomial::Poly;
