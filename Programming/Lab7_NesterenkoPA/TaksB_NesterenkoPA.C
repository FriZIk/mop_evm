/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: B. Делители числа
Дата: 14.12.2019
*/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    if( n == 1)printf("1");
    else
    {
        for(int i = 1;i <= n;i++)
            if(n % i == 0)printf("%d\n",i);
    }
    return 0;
}