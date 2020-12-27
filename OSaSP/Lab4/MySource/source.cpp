/*
Процесс порождает 10 дополнительных нитей, каждая из которых выдает на экран
сообщение о своем запуске и свой номер. Далее в цикле основная нить задает
пользователю вопрос, какую нить надо завершить. Когда завершены все
дополнительные нити, завершается и весь процесс.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

#define NUMBER_OF_THREADS 10 // Количество создаваемыъ процессов
HANDLE hThreads[NUMBER_OF_THREADS];

DWORD WINAPI StartThread(CONST LPVOID lpParam)
{
    int c = (*((int*)lpParam)) + 1;
    printf("Нить под номером %d - запущена\n", c);
    while (true)
    {
        Sleep(100);
    }
    ExitThread(0);
}

void GetThreads()
{
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        if (hThreads[i] != NULL && WaitForSingleObject(hThreads[i], 1))
            hThreads[i] = NULL;
        else printf("%d, ", i);
    }
}

int main(void)
{
    setlocale(LC_ALL, "Russian");
    DWORD dwThreadNumber[NUMBER_OF_THREADS], dwThreadIds[NUMBER_OF_THREADS];

    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        Sleep(10);
        dwThreadNumber[i] = i;
        hThreads[i] = CreateThread(NULL, 0, &StartThread, &dwThreadNumber[i], 0, &dwThreadIds[i]);
        if (hThreads[i] == NULL)
            printf("Ошибка при создании потока: %d.\n", GetLastError());
    }

    printf("===================================\n");
    int Counter = NUMBER_OF_THREADS;
    while (Counter > 0)
    {
        Sleep(10);
        printf("Удалить поток под номером:");
        int NumberOfThread;
        scanf("%d", &NumberOfThread);
        
        if (NumberOfThread > 1 && NumberOfThread < NUMBER_OF_THREADS && hThreads[NumberOfThread - 1] != NULL)
        {
            TerminateThread(hThreads[NumberOfThread - 1], 0);
            printf("Был удалён поток c идентификатором: %d \n", dwThreadIds[NumberOfThread - 1]);

            printf("Работающие потоки:");
            GetThreads();
            Counter--;
            printf("\n");
        }
        else printf("Введённые данные не корректны!!!\n");
    }
    printf("Все потоки удалены!\n");
    return 0;
}