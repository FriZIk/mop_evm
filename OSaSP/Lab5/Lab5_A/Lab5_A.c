/*
Процесс A в цикле просит пользователя ввести 5 чисел и затем
передает их процессу B. Процесс B отображает на экране эти числа
в обратном порядке и спрашивает пользователя, продолжить работу
или завершить процессы. Для передачи данных используется отображение
страничного файла.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <windows.h>
#include <stdlib.h>
#include <io.h>
#include <Fcntl.h>
#include <locale.h>

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int errCode;
	HANDLE hMapping, hDataSentEvent, hChooseEvent;
	HANDLE hAnswerEvent;
	int* Array;
	int* triger;
	BOOL procBRuns;
	STARTUPINFO startInfo = { sizeof(startInfo) };
	PROCESS_INFORMATION procInfo;
	SECURITY_ATTRIBUTES pipeAttributes = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };

	hMapping = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4096, _T("Lab5_Mapping"));
	Array = MapViewOfFile(hMapping, FILE_MAP_WRITE, 0, 0, 250);
	triger = MapViewOfFile(hMapping, FILE_MAP_WRITE, 0, 0, 2);
	hDataSentEvent = CreateEvent(NULL, FALSE, FALSE, _T("Lab5"));
	hAnswerEvent = CreateEvent(NULL, FALSE, FALSE, _T("Lab5"));
	hChooseEvent = CreateEvent(NULL, FALSE, FALSE, _T("Lab5"));

	procBRuns = CreateProcess(_T("..\\Debug\\Lab5_B.exe"), NULL, NULL, NULL, TRUE,
		CREATE_NEW_CONSOLE, NULL, NULL, &startInfo, &procInfo);

	if (!procBRuns) {
		errCode = 1;
		printf("%s", "Не удалось запустить процесс B\n");
		getchar();
		return 1;
	}

	WaitForSingleObject(hAnswerEvent, INFINITE);
	do {
		printf("%s", "Введите 5 чисел: ");
		for (int i = 0; i < 5; i++)
			scanf("%d", &Array[i]);

		SetEvent(hDataSentEvent);
		WaitForSingleObject(hAnswerEvent, INFINITE);
		printf("===============================================\n\n");
	} while (triger[0] == 1);
	
	
	UnmapViewOfFile(Array);
	CloseHandle(hMapping);

	return 0;
}