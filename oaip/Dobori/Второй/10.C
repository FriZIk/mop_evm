/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: I. Общие множители
Дата: 25.01.2020
*/

#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int first = 0;

    for(int i = 2;i <= b;i++)
    {
        if(a % i == 0 && b % i == 0)
        {
            int triger = 1;
            for(int j = 1;j < i;j++)
            {
                if(i%j == 0)triger++;
            }
            if(triger == 2)
            {
                first++;
                printf("%d",i);
            }
        }
    }
    if(first == 0)printf("-1");

    return 0;
}

//00 не делящиеся на 400