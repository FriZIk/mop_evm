#include <iostream>
#include <Windows.h>

int counter = 10;
HANDLE thread[10];
DWORD threadId[10];
int threadParams[10];

DWORD WINAPI threadFunc(LPVOID lpvThreadParam) {
    int c = (*((int*)lpvThreadParam));
    while (true) {
        printf("%s %d %s", "Thread #", c, "is running\n");
        Sleep(1000);
    }
    return(0);
}

void checkAlive() {
    for (int i = 0; i < 10; i++)
        if (thread[i]!=NULL && WAIT_TIMEOUT != WaitForSingleObject(thread[i], 1)) {
            thread[i] = NULL;
            counter--;
        }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    for (int i = 0; i < counter; i++) {
        threadParams[i] = i+1;
        thread[i] = CreateThread(NULL, 0, &threadFunc, &threadParams[i], 0, &threadId[i]);
    }
    int threadNumber;

    while (true) {
        Sleep(10);
        std::cout << "Введите номер останавливаемого потока(1-10) - ";
        std::cin >> threadNumber;
        if (threadNumber > 10 || threadNumber < 1 || thread[threadNumber-1] == NULL) {
            std::cout << "Введены неверные данные или поток уже был остановлен\n";
        } else {
            TerminateThread(thread[threadNumber - 1], 0);
            std::cout << "Поток #" << threadNumber << " был остановлен\n";
        }

        checkAlive();
        std::cout << "На данный момент " << counter << " потоков работает\n";
        if (counter <= 0) {
            break;
        }
    }
}
