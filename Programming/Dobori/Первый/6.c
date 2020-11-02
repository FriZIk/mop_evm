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
    long long int sum = 0;

    for(int i = a;i <= b;i++)
    {
        int triger = 1;
        for(int j = 1;j < i;j++)
        {
            if(i%j == 0)triger++;
        }
        if(triger == 2)sum = sum + i;
    }
    printf("%d",sum);Например есл
    return 0;
}
