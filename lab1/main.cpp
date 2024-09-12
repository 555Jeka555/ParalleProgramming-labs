#include <windows.h>
#include <string>
#include <iostream>
#include <tchar.h>

DWORD WINAPI ThreadProc(CONST LPVOID lpParam)
{
    int threadNumber = *static_cast<int*>(lpParam);

    std::cout << "Полезная работа потока " << threadNumber << "\n";

    ExitThread(0);
}

int _tmain(int argc, _TCHAR* argv[])
{
    int n;
    std::cout << "Введите кол-во потоков" << std::endl;
    std::cin >> n;

    HANDLE* handles = new HANDLE[n];
//    int** threadNums = new int*[n];
    for (int i = 0; i < n; i++)
    {
        int* threadNum = new int(i + 1);
        handles[i] = CreateThread(NULL, 0, &ThreadProc, threadNum, 0, NULL);
//        threadNums[i] = threadNum;
    }

    WaitForMultipleObjects(n, handles, true, INFINITE);

    for (int i = 0; i < n; ++i) {
        CloseHandle(handles[i]);
    }

//    delete[] threadNums;
    delete[] handles;
    return 0;
}
