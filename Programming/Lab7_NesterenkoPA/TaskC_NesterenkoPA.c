/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: C. Нечётных в интервале
Дата: 14.12.2019
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    scanf("%d",&n);
    int *a = (int *)malloc(n * sizeof(int));
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    
    int l,r;
    scanf("%d %d",&l,&r);
    int count = 0;
    for(int i = l;i <= r;i++)
        if(a[i] % 2 != 0)count++;
    printf("%d",count);
    return 0;
}