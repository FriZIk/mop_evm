/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: D. Лампочка
Дата: 25.01.2020
*/

#include <stdio.h>

int main()
{
    float N;
    scanf("%f",&N);
    if(N > 25 && N <= 100)printf("GREEN");
    else printf("RED");
    return 0;
}