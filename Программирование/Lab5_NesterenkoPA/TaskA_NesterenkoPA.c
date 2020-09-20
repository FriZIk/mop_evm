#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("input.txt", "rt");// Поток откртия файла на чтение
    
    int n = 10000,ic,len = 0;
    char buf[n];
    while((ic = fgetc(file)) != EOF)
    {
        buf[len] = (char)ic;
        len++;
    }
    for(int i = 0;i < len;i++)printf("%c",buf[i]);
    

    char **str = NULL;
    str = (char **)malloc(n * sizeof(char*));
    for(int i = 0;i < n;i++)
        str[i] = (char*)malloc(n * sizeof(char));

    int
    scanf("")
    printf("\n");
    return 0;
}