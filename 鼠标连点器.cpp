#include<iostream>
#include<Windows.h>
int main()
{
	int n, sum = 0;
	std::cout << "����������Ƶ��(����)" << std::endl;
	std::cin >> n;
	std::cout << "���¿ո�ʼִ�У���esc�˳�" << std::endl;
    while(true)
    {
        if(GetAsyncKeyState(VK_SPACE))//���¿ո񣬿�ʼִ��
        {
        	std::cout << "��ʼִ�У�" << std::endl;
            while(true)
            {
                mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);//��ǰλ�õ��һ�����
                sum++;
                Sleep(n);
                if(GetAsyncKeyState(VK_ESCAPE)) //��esc�˳�
                {
					std::cout << "����ִ�У���ִ��" << sum << "��" << std::endl;
	                return 0;
				}
            }
        }
    }
    return 0;
}

