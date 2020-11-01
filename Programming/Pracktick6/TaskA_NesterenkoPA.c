/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: A. «Интересный» урок
Дата: 19.12.2019
*/
#include <stdio.h>

int main()
{
    const int n = 102;
    char str[n],str1[n];
    scanf("%s %s",str,str1);
    int len = 0,len1 = 0;
    for(char *p_str = str;*p_str;p_str++,len++);
    for(char *p_str1 = str1;*p_str1;p_str1++,len1++);
    int count = 0;    
    if(len1 == len == 1)count = 1;
    if(len == 0 || len1 == 0)count = 0;
    else
    {
        for(int i = 0;i < len;i++)
        {
            int triger = 0;
            int i_b = i;
            for(int j = len1;j >= 0;j--,i_b++)
            {
                if(*(str + i_b) == *(str1 + j))
                    triger++;
            }
            if(triger == len1)
            {
                count++;
            }
            triger = 0;
        }
    }
    printf("%d",count);
    return 0;
}