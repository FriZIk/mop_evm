/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: D. Лампочка
Дата: 25.01.2020
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    if(a == b + c || b == a + c || c == b + a)printf("0.00");
    return 0;
}