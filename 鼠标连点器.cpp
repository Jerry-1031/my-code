#include<iostream>
#include<Windows.h>
int main()
{
	int n, sum = 0;
	std::cout << "请输入点击的频率(毫秒)" << std::endl;
	std::cin >> n;
	std::cout << "按下空格开始执行，按esc退出" << std::endl;
    while(true)
    {
        if(GetAsyncKeyState(VK_SPACE))//按下空格，开始执行
        {
        	std::cout << "开始执行！" << std::endl;
            while(true)
            {
                mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);//当前位置点击一次鼠标
                sum++;
                Sleep(n);
                if(GetAsyncKeyState(VK_ESCAPE)) //按esc退出
                {
					std::cout << "结束执行！共执行" << sum << "次" << std::endl;
	                return 0;
				}
            }
        }
    }
    return 0;
}

