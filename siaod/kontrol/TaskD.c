/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: D - Размен монет
Дата: 16.05.2020
*/

#include <stdio.h>

int main()
{
    // есть толькл монеты 1 4 7
    int a; // сумма покупки
    int counter = 0;

    scanf("%d",&a);
    int temp;
    while(a-7 >= 0)
    {
        temp = a;
        a = a-7;
        counter++;
        temp = a;
    }

    while(a - 4 >= 0)
    {
        temp = a;
        a = a-4;
        counter++;
        temp = a;
    }
    counter = counter + a;

    printf("%d",counter);

    return 0;
}
