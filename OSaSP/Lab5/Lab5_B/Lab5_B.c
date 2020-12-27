#include "stdafx.h"
#include "windows.h"
#include <stdlib.h>
#include <locale.h>

int main(void)
{
	int* arrayReceived;
	int* triger;
	HANDLE hMapping, hReceivedEvent, hAnswerEvent, hStopEvent;

	hMapping = OpenFileMapping(FILE_MAP_WRITE, FALSE, _T("Lab5_Mapping"));
	arrayReceived = MapViewOfFile(hMapping, FILE_MAP_WRITE, 0, 0, 250);
	triger = MapViewOfFile(hMapping, FILE_MAP_WRITE, 0, 0, 2);
	hReceivedEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, _T("Lab5"));
	hAnswerEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, _T("Lab5"));
	
	SetConsoleCP(1251);			
	SetConsoleOutputCP(1251);	

	puts("");
	fflush(stdout);

	SetEvent(hAnswerEvent);

	do {
		int choose = 1;
		WaitForSingleObject(hReceivedEvent, INFINITE);
		printf("Получено от A:");
		for(int i = 4;i >= 0;i--)
			printf("%d ", arrayReceived[i]);
		printf("\nПрододжить выполение?(1/0):");
		scanf("%d", &choose);
		triger[0] = choose;
		SetEvent(hAnswerEvent);
	} while (triger[0] == 1);

	SetEvent(hAnswerEvent);
	UnmapViewOfFile(arrayReceived);

	CloseHandle(hMapping);

	return 0;
}

