/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: C - Строка на слова
Дата: 21.11.2019
*/
#include <stdio.h>
#include <string.h>

void func(char * str, int len)
{
    int first = *(strchr(str,' '));
    for(int i = 0;i < len;i++)
    {
        if(isspace(str[i]) == 0)
        {
            for(int j = i + 1;isspace(str[i]) == 0;j++)
            {    
                printf("%c",str[i]);
                i = j;
            }
            if(i != len - 1)
            printf("\n");
        }
    }
}

int main()
{
    const int n = 1000;
    char str[n];
    fgets(str,n,stdin);
    int len = strlen(str);
    func(str,len);
    return 0;
}