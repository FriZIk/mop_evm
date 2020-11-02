/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: 
Дата: 28.01.2020
*/

#include <stdio.h>

int main()
{
    const int N = 101;
    int n = 0;
    scanf("%d",&n);
    int a[N];
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);

    int sum = 0;
    for(int i = 0;i < n;i++)
        if(a[i] > 25 && a[i]%2 == 0)sum = sum + (i+1);

    if(sum == 0)
    {
        for(int i = 1;i < n;i++)
            sum = sum + i;
    }
    printf("%d",sum);
    return 0;
}