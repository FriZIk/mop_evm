/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: A. Делимость
Дата: 10.10.2019
*/

#include <stdio.h>

int main(void)
{
    int a,b;
    scanf("%d %d",&a,&b);
    if(a%b == 0 || b%a == 0)printf("YES");
    else printf("NO");
    return 0;
}