#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <windows.h>
using namespace std;

class CppMouse
{
public:
	CppMouse()
	{
		screen_x = GetSystemMetrics(SM_CXSCREEN);
		screen_y = GetSystemMetrics(SM_CYSCREEN);
	}
	inline vector<int> screen_size()
	{
		return {screen_x, screen_y};
	}
	vector<int> position()
	{
		POINT p;
		GetCursorPos(&p);
		vector<int> pos = {p.x, p.y};
		return pos;
	}
	inline void move(int x, int y)
	{
		mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, getx(x), gety(y), 0, 0);
	}
	void click(int x, int y, int button, int n = 1)
	{
		move(x, y);
		for(int i = 0; i < n; i++)
		{
			if(button == 1)
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}
			else if(button == 2)
			{
				mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			}
		}
	}
private:
	int screen_x, screen_y;
	inline int getx(int x)
	{
		return x * 65536 / screen_x;
	}
	inline int gety(int y)
	{
		return y * 65536 / screen_y;
	}
};

class CppKeyBoard
{
public:
	CppKeyBoard()
	{
		init_keys();
	}
	inline void press_key(int key_code)
	{
		keybd_event(key_code, 0, 0, 0);
	}
	inline void press_key(char key)
	{
		press_key(keymap[key]);
	}
	inline void release_key(int key_code)
	{
		keybd_event(key_code, 0, KEYEVENTF_KEYUP, 0);
	}
	inline void release_key(char key)
	{
		release_key(keymap[key]);
	}
	void tap_key(int key_code, int n = 1, int interval = 0)
	{
		for(int i = 0; i < n - 1; i++)
		{
			press_key(key_code);
			release_key(key_code);
			Sleep(interval * 1000);
		}
		press_key(key_code);
		release_key(key_code);
	}
	inline void tap_key(char key, int n = 1, int interval = 0)
	{
		tap_key(keymap[key], n, interval);
	}
	void type_string(string str)
	{
		int len = str.length();
		for(int i = 0; i < len; i++)
			if(isup(str[i]))
			{
				press_key(16);
				tap_key(str[i]);
				release_key(16);
			}
			else
				tap_key(str[i]);
	}
	int backspace_key = 8;
	int tab_key = 9;
	int enter_key = 13;
	int shift_key = 16;
	int control_key = 17;
	int alt_key = 18;
	int capslock_key = 20;
	int esc_key = 27;
	int left_key = 37;
	int up_key = 38;
	int right_key = 39;
	int down_key = 40;
	int delete_key = 46;
	int numlock_key = 144;
	map<int, int> function_keys;
	map<int, int> numpad_keys;
private:
	map<char, int> keymap;
	string calpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lalpha = "abcdefghijklmnopqrstuvwxyz";
	string upnum = ")!@#$%^&*(";
	string ufunc = ":+<_>?~{|}\"";
	string func = ";:=+,<-_.>/?`~[{\\|]}'\"";
	void init_keys()
	{
		for(int i = 0; i < 26; i++)
		{
			keymap[calpha[i]] = i + 65;
			keymap[lalpha[i]] = i + 65;
		}
		for(int i = 0; i < 10; i++)
		{
			keymap[char(i)] = i + 48;
			keymap[upnum[i]] = i + 48;
		}
		keymap[' '] = 32;
		for(int i = 0; i < 11; i++)
		{
			keymap[func[i * 2]] = i + 186;
			keymap[func[i * 2 + 1]] = i + 186;
		}
		for(int i = 1; i < 13; i++)
		{
			function_keys[i] = i + 111;
		}
		for(int i = 0; i < 10; i++)
		{
			numpad_keys[i] = i + 96;
		}
	}
	bool isup(char key)
	{
		string all = calpha + upnum + ufunc;
		int len = all.length();
		for(int i = 0; i < len; i++)
			if(all[i] == key)
				return true;
		return false;
	}
};

template<typename T1, typename T2>
void press_two_keys(T1 key1, T2 key2, CppKeyBoard k)
{
	k.press_key(key1);
	k.tap_key(key2);
	k.release_key(key1);
}

int main()
{
	CppMouse mouse;
	vector<int> size = mouse.position();
	int x = size[0], y = size[1];
	mouse.click(x, y, 1, 1);
	CppKeyBoard k;
	k.type_string("I automatically input this text in C++ code.");
	press_two_keys(k.control_key, k.enter_key, k);
	k.type_string("This is a new version with brackets, more function keys, more control keys and numeric keypad.");
	k.tap_key(k.enter_key);
	return 0;
}
