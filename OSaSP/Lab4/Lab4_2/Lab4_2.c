#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

#define NUMBER_OF_THREADS 10 // Количество создаваемыъ процессов

DWORD WINAPI ThreadProc(CONST LPVOID lpParam) {
    CONST HANDLE hMutex = (CONST HANDLE)lpParam;
    printf("Я родился, номер:%d.\n", *(DWORD*)lpParam);
    ReleaseMutex(hMutex);
    ExitThread(0);
}

int main(void)
{
    setlocale(LC_ALL, "Russian");
    HANDLE hThreads[NUMBER_OF_THREADS];
    DWORD Number;

    CONST HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONST HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        Number = i;
        //hThreads[i] = CreateThread(NULL, 0, &ThreadProc, &Number, 0, NULL);
        hThreads[i] = CreateThread(NULL, 0, &ThreadProc, hMutex, 0, NULL);
        if (hThreads[i] == NULL)
            printf("CreateThread() failed, error: %d.\n", GetLastError());
    }
    return 0;
}