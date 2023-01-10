//极域电子教室killer 转自Dancing_Wave大佬
#include<bits/stdc++.h>
#include<time.h>
#include<math.h>
#include <iostream>
#include <stdio.h>  
#include <windows.h>  
#include <TlHelp32.h>  
#include <stdlib.h>
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
using namespace std;
int Kill_Pro(TCHAR Kill_Name[])
{
	int t=time(0)+1;
    HANDLE hSnapshort = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);  
    if( hSnapshort==INVALID_HANDLE_VALUE )  
    {  
        printf("CreateToolhelp32Snapshot wrong!\n");  
        return -1;  
    }  
  if(time(0)>=t){
  	return 0;
  }

    PROCESSENTRY32 stcProcessInfo;  
    stcProcessInfo.dwSize = sizeof(stcProcessInfo);  
    BOOL  bRet = Process32First(hSnapshort, &stcProcessInfo);  
    while (bRet)  
    {  
		if(strcmp(stcProcessInfo.szExeFile,Kill_Name)==0)
		{	
            HANDLE hProcess = ::OpenProcess(PROCESS_TERMINATE,FALSE,stcProcessInfo.th32ProcessID);
            ::TerminateProcess(hProcess,0);
            CloseHandle(hProcess);		
		}
        bRet = Process32Next(hSnapshort, &stcProcessInfo);  
    }  
  
    CloseHandle(hSnapshort);  
 
	
	return 0;
}
bool improvePv() {
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken)) return false;
	if (!LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid)) return false;
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, NULL, NULL, NULL)) return false;
	return true;
}
int main()
{
	bool a=improvePv();
	Sleep(5000);

	while(1){
		Sleep(300);
		Kill_Pro("StudentMain.exe");
		Kill_Pro("Shutdown.exe");
	}
	main();
	return 0;
}

//StudentMain.exe360Safe.exe
