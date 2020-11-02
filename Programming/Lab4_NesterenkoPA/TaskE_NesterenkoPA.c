/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: E - Водолаз Миша
Дата: 21.11.2019
*/
#include <stdio.h>

int recursive(int a,int result,int temp_a)
{
    if(a > 1)recursive(a - 1,result * temp_a,temp_a);
    else return result;
}

int main()
{
    long long int a;
    scanf("%d",&a);
    printf("%d",recursive(a,a,a));
    return 0;
}