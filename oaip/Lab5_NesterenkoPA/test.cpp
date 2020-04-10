#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file = fopen("input.txt", "rt");
    char str[10000];
    int i = 3;
    
    const int n = 3;
    char **str1 = NULL;
    str1 = (char **)malloc(n * sizeof(char*));
    for(int i = 0;i < n;i++)
        str1[i] = (char*)malloc(n * sizeof(char));

    int n1,sum,len;
    while(!feof(file))
    {
        str1[0] = fgets(str,sizeof(str),file);
        n1 = atoi(str1[0]);
        str1[1] = fgets(str,sizeof(str),file);
        len = strlen(str);
        fputs(str1[1],stdout);
        str1[2] = fgets(str,sizeof(str),file);
        sum = atoi(str1[2]);
    }
    printf("%d %d %d",n1,sum,len);
    
    int realsum = 0;
    return 0;
}