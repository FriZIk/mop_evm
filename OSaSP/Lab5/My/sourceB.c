#include "stdafx.h"
#include "windows.h"
#include <stdlib.h>
#include <locale.h>

int main(void)
{
	int* arrayReceived;
	HANDLE hMapping, hReceivedEvent, hAnswerEvent, hStopEvent;

	hMapping = OpenFileMapping(FILE_MAP_WRITE, FALSE, _T("Lab5_Mapping"));
	arrayReceived = MapViewOfFile(hMapping, FILE_MAP_WRITE, 0, 0, 250);
	
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
		if (choose == 0)break;
		else SetEvent(hAnswerEvent);
		fflush(stdout);
	} while (1);
	
	UnmapViewOfFile(arrayReceived);

	CloseHandle(hMapping);

	return 0;
}

