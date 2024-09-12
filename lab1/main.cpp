#include <windows.h>
#include <string>
#include <iostream>
#include <tchar.h>

DWORD WINAPI ThreadProc(CONST LPVOID lpParam)
{
//
// ?? тут выполняется полезная работа потока
//
    int threadNumber = *static_cast<int*>(lpParam);

    Sleep(250);

    std::cout << "Полезная работа потока " << threadNumber << "\n";

    Sleep(250);

    ExitThread(0); // функция устанавливает код завершения потока в 0
}

int _tmain(int argc, _TCHAR* argv[])
{
    int n;
    std::cout << "Введите кол-во потоков" << std::endl;
    std::cin >> n;

// создание двух потоков
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

// ожидание окончания работы двух потоков
    WaitForMultipleObjects(n, handles, true, INFINITE);
    return 0;
}
