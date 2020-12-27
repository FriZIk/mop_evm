#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	int sum = 0;
	int x = 0;
	while (1) {
		scanf("%d",&x);
		printf("%s %d\n","The sum is",sum += x);
	}
}

