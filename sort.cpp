void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
bool cmp(const int &x, const int &y)
{
	return x < y;
}
void sort(int* a, int l, int r)
{
	if (r - l < 2) return;
	swap(a[l], a[(l + r) / 2]);
	int p = l + 1;
	for(int i = l + 1; i < r; i++)
		if(cmp(a[i], a[l]))
			swap(a[i], a[p++]);
	swap(a[l], a[p - 1]);
	sort(a, l, p - 1);
	sort(a, p, r);
}

#include <cstdlib>
void sort(unsigned *a, const int len)
{
	unsigned *b = malloc(sizeof(unsigned ) * len);
	int sum[256] = {0}, sum1[256] = {0}, sum2[256] = {0}, sum3[256] = {0};
	for (int i = 0; i < len; i++)
	{
		++sum[a[i] & 255];
		++sum1[(a[i] >> 8) & 255];
		++sum2[(a[i] >> 16) & 255];
		++sum3[a[i] >> 24];
	}
	for (int q = 1; q <= 255; ++q)
	{
		sum[q] += sum[q - 1];
		sum1[q] += sum1[q - 1];
		sum2[q] += sum2[q - 1];
		sum3[q] += sum3[q - 1];
	}
	for (int q = len - 1; q >= 0; --q)
		b[--sum[a[q] & 255]] = a[q];
	for (int q = len - 1; q >= 0; --q)
		a[--sum1[(b[q] >> 8) & 255]] = b[q];
	for (int q = len - 1; q >= 0; --q)
		b[--sum2[(a[q] >> 16) & 255]] = a[q];
	for (int q = len - 1; q >= 0; --q)
		a[--sum3[b[q] >> 24]] = b[q];
	free(b);
	return;
}
