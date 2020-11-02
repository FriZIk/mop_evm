/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: A - Сумма двух
Дата: 21.11.2019
*/

#include <stdio.h>

long long int sum(long long int a,long long int b)
{
    return a + b;
}

int main()
{
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld",sum(a,b));
    return 0;
}