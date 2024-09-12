#include <windows.h>
#include <string>
#include <iostream>
#include <tchar.h>

DWORD WINAPI ThreadProc(CONST LPVOID lpParam)
{
    int threadNumber = *static_cast<int*>(lpParam);

    Sleep(250);

    std::cout << "Полезная работа потока " << threadNumber << "\n";

    Sleep(250);

    ExitThread(0);
}

int _tmain(int argc, _TCHAR* argv[])
{
    int n;
    std::cout << "Введите кол-во потоков" << std::endl;
    std::cin >> n;

    HANDLE* handles = new HANDLE[n];
    for (int i = 0; i < n; i++)
    {
        int* threadNum = new int(i + 1);
        handles[i] = CreateThread(NULL, 0, &ThreadProc, threadNum, 0, NULL);
    }

    for (int i = 0; i < n; i++)
    {
        ResumeThread(handles[i]);
    }

    WaitForMultipleObjects(n, handles, true, INFINITE);

    for (int i = 0; i < n; ++i) {
        CloseHandle(handles[i]);
    }

    delete[] handles;
    return 0;
}
