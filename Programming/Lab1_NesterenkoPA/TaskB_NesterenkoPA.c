/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: B
Дата: 05.10.2019
*/

#include <stdio.h>

int main(void)
{
    int a,b; //a - деньги , b - стоимость
    scanf("%d %d",&a,&b);
    int c = 0; // максимальное кол-во
    int d = 0; // сдача
    c = a / b;
    d = a % b;
    printf("%d\n%d",c,d);
    return 0;
}