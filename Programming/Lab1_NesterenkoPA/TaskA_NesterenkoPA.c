/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: A
Дата: 05.10.2019
*/

#include <stdio.h>

int main(void)
{
    int a,b;
    scanf("%d %d",&a,&b);
    int S = a * b;
    int P = 2*(a + b);
    printf("%d %d",S,P);
    return 0;
}