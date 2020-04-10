/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: I - Мин-Макс-Среднее
Дата: 21.11.2019
*/
#include <stdio.h>

void MinMaxSred(double *ar1,double *ar2,int n1)
{
    int Max,Min,Sred;
    Max = -10000000;
    Min = 10000000;
    Sred = 0;
}


int main()
{
    const int n = 1000;
    int a[n];
    int n1;
    scanf("%f",&n1);
    for(int i = 0;i < n1;i++)
        scanf("%d",&a[i]);

    for(int i = 0;i < n1;i++)
        printf("%d",a[i]);
    return 0;
}