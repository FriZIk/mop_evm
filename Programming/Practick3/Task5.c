#include <stdio.h>
#include <string.h>
//Поиск всех подстрок в строрк

int StrFindMatch(char *str,char * tmp1)
{
    while(*str && *tmp1 && (*str == *tmp1))
    {
        str++;
        tmp1++;
    }
    return !(*tmp1);
}


int main(void)
{
    const int n = 10000;
    char *a;
    char str[n],str1[n];
    int len,len1;

    // Ввод исходной строки
    fgets(str,n,stdin);
    a = str;
    for(a;*a;a++,len++);

    //Ввод строки,которую будем искать
    fgets(str1,n,stdin);
    a = str1;
    for(a;*a;a++,len1++);

    int N = len - len1;
    for(int i = 0;i < N;i++)
    {
        if(StrFindMatch(str,str1) == 1)
            printf("%d ",i + 1);
        str++;
    }

    return 0;
}