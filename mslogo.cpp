/*  This program is making
    Microsoft Caption.
    With output file format bmp.*/

#include <windows.h>
typedef unsigned long u32;
typedef unsigned char byte;
byte *t;
void *o;
u32 c, sh, sw, s;
u32 bor, len, gap, map;
u32 back, red, green, blue, yellow;
void set32(u32 p, u32 d)
{
	for(u32 i = 0; i < 4; ++i)
	{
		t[p + i] = d;
		d >>= 8;
	}
}
u32 getpos(u32 i, u32 j)
{
	return 54 + ((i * map + j) << 2);
}
void ini()
{
	t[0] = 'B';
	t[1] = 'M';
	set32(0x02, s);
	set32(0x0a, 54);
	set32(0x0e, 40);
	set32(0x12, map);
	set32(0x16, map);
	set32(0x1c, 32);
	t[0x1a] = 1;
}
u32 setup()
{
	u32 i, j, k, l;
	bor = 24;
	len = 25;
	gap = 2;
	map = gap + ((bor + len) << 1);
	s = 54 + ((map * map) << 2);
	ini();
	back = 0x00f5f5f5;
	blue = 0x0000adef;
	yellow = 0x00fbbc09;
	red = 0x00f1511b;
	green = 0x0080cc28;
	/*  Hard code!
	    Got in std Microsoft Caption.*/
	for(i = 0; i < bor; ++i)
		for(j = 0; j < map; ++j)
			set32(getpos(i, j), back);
	for(k = 0; k < len; ++i, ++k)
	{
		for(j = 0; j < bor; ++j)
			set32(getpos(i, j), back);
		for(l = 0; l < len; ++j, ++l)
			set32(getpos(i, j), blue);
		for(l = 0; l < gap; ++j, ++l)
			set32(getpos(i, j), back);
		for(l = 0; l < len; ++j, ++l)
			set32(getpos(i, j), yellow);
		for(; j < map; ++j)
			set32(getpos(i, j), back);
	}
	for(k = 0; k < gap; ++i, ++k)
		for(j = 0; j < map; ++j)
			set32(getpos(i, j), back);
	for(k = 0; k < len; ++i, ++k)
	{
		for(j = 0; j < bor; ++j)
			set32(getpos(i, j), back);
		for(l = 0; l < len; ++j, ++l)
			set32(getpos(i, j), red);
		for(l = 0; l < gap; ++j, ++l)
			set32(getpos(i, j), back);
		for(l = 0; l < len; ++j, ++l)
			set32(getpos(i, j), green);
		for(; j < map; ++j)
			set32(getpos(i, j), back);
	}
	for(; i < map; ++i)
		for(j = 0; j < map; ++j)
			set32(getpos(i, j), back);
	return s;
}
int main()
{
	t = new byte[1048576];
	o = CreateFileA("Microsoft.bmp", GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if(o == 0)
	{
		MessageBoxA(0, "CreateFile Failed!", "Process", MB_OK | MB_ICONSTOP);
		return 0;
	}
	s = setup();
	WriteFile(o, (void*)t, s, &c, 0);
	CloseHandle(o);
	return 0;
}
