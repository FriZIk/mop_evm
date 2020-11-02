/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: A - Максимум из трёх
Дата: 14.12.2019
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 3;
    int max = -1001;
    int *a = (int *)malloc(n * sizeof(int));
    
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);

    for(int i = 0;i < n;i++)
        if(a[i] > max)max = a[i];

    printf("%d",max);
    free(a);
    return 0;
}