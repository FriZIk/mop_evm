/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: 
Дата: 28.01.2020
*/

#include <stdio.h>

int main()
{
    int k = 0;
    scanf("%lld",&k);

    int sum = 0;
    for(int i = 1;i <= k + 1;i++)
        sum = i + sum;
    
    //printf("%d\n",sum);
    // 1 + 2 + 3 + 4 + 5 = 15
    // 1 2 4 5
    for(int i = 0;i < k;i++)
    {
        int a = 0;
        scanf("%d",&a);
        sum = sum - a;
        //printf("%d",sum);
    }

    printf("%d",sum);
    return 0;
}