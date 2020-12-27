// For WinXp as a target
#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <stdio.h>
#include <conio.h>

DWORD WINAPI MyThreadFunction(LPVOID lpParam)
{
	printf("The parameter: %u.\n", *(DWORD*)lpParam);
	return 0;
}

int main(void)
{
	DWORD dwThreadId, dwThrdParam = 1;
	HANDLE hThread;
	int x;
	// Let try a loop...
	for (x = 1; x <= 10; x++)
	{
		hThread = CreateThread(
			NULL, // default security attributes
			0, // use default stack size
			MyThreadFunction, // thread function
			&dwThrdParam, // argument to thread function
			0, // use default creation flags
			&dwThreadId); // returns the thread identifier
			// Check the return value for success. If something wrong...
		if (hThread == NULL)
			printf("CreateThread() failed, error: %d.\n", GetLastError());
		else
		{
			printf("It seems the CreateThread() is OK lol!\n");
			printf("The thread ID: %u.\n", dwThreadId);
		}
		if (CloseHandle(hThread) != 0)
			printf("Handle to thread closed successfully.\n");

	} // end for loop...
	return 0;
}