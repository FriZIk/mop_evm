#include <windows.h>
#include <iostream>
#include <io.h>
#include <stdio.h>
#include <fcntl.h>


STARTUPINFO startupInfoA;
STARTUPINFO startupInfoB;
PROCESS_INFORMATION procInfoA;
PROCESS_INFORMATION procInfoB;
TCHAR cLine[] = TEXT("Proc");


HANDLE hWritePipeA;
HANDLE hWritePipeB;
HANDLE hReadPipeA;
HANDLE hReadPipeB;


void closeHandles() {
	TerminateProcess(procInfoA.hProcess, 9);
	TerminateProcess(procInfoB.hProcess, 9);
	CloseHandle(procInfoA.hProcess);
	CloseHandle(procInfoA.hThread);
	CloseHandle(procInfoB.hProcess);
	CloseHandle(procInfoB.hThread);
}

int createProcess(TCHAR* cl, STARTUPINFO* sInfo, PROCESS_INFORMATION* pInfo) {
	return CreateProcess(
		NULL,
		cl,
		NULL,
		NULL,
		TRUE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		sInfo,
		pInfo
	);
}

int main() {
	setlocale(0, "Russian");

	SECURITY_ATTRIBUTES saAttrA = {
		sizeof(SECURITY_ATTRIBUTES),
		NULL,
		TRUE
	};

	SECURITY_ATTRIBUTES saAttrB = {
		sizeof(SECURITY_ATTRIBUTES),
		NULL,
		TRUE
	};

	if (
		CreatePipe(&hReadPipeA, &hWritePipeA, &saAttrA, 0) &&
		CreatePipe(&hReadPipeB, &hWritePipeB, &saAttrB, 0)
		) {
		std::cout << "PIPES - OK\n";
	}
	else {
		std::cout << "PIPES - ERROR\n";
		return 1;
	}

	ZeroMemory(&procInfoA, sizeof(PROCESS_INFORMATION));
	ZeroMemory(&startupInfoA, sizeof(STARTUPINFO));
	startupInfoA.cb = sizeof(STARTUPINFO);

	ZeroMemory(&procInfoB, sizeof(PROCESS_INFORMATION));
	ZeroMemory(&startupInfoB, sizeof(STARTUPINFO));
	startupInfoB.cb = sizeof(STARTUPINFO);

	//переопределяем стандартный ввод в процессах-потомках
	startupInfoA.dwFlags = STARTF_USESTDHANDLES;
	startupInfoB.dwFlags = STARTF_USESTDHANDLES;
	startupInfoA.hStdInput = hReadPipeA;
	startupInfoB.hStdInput = hReadPipeB;
	
	if (createProcess(cLine, &startupInfoA, &procInfoA) && createProcess(cLine, &startupInfoB, &procInfoB)) {
		cout << "PROCESSES - OK\n";
	}
	else {
		std::cout << "PROCESSES - ERROR\n";
		closeHandles();
		return 1;
	}
	CloseHandle(hReadPipeA);
	CloseHandle(hReadPipeB);

	int x;
	char procLit;
	 
	FILE* pipeA = _fdopen((HFILE)_open_osfhandle((intptr_t)hWritePipeA, _O_TEXT),"a+t");
	FILE* pipeB = _fdopen((HFILE)_open_osfhandle((intptr_t)hWritePipeB, _O_TEXT),"a+t");

	while (true) {
		std::cout << "Write a number -> ";
		std::cin >> x;
		
		if (x == 0) {
			break;
		}

		std::cout << "Write the name of proccess (A/B) -> ";
		std::cin >> procLit;
		
		if (procLit == 'A' || procLit == 'a') {
			fprintf(pipeA, "%d\n", x);
			fflush(pipeA);
		}
		else if (procLit == 'B' || procLit == 'b') {
			fprintf(pipeB, "%d\n", x);
			fflush(pipeB);
		}
		else {
			break;
		}

	}

	fclose(pipeA);
	fclose(pipeB);

	closeHandles();
	return 0;
}
