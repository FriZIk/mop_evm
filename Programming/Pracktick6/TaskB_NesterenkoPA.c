/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: A. «Интересный» урок
Дата: 19.12.2019
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(m * sizeof(int));

    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    for(int i = 0;i < m;i++)
        scanf("%d",&b[i]);

    //Остортировать по возрастанию без сортировки

    long long int min = 10000000000;
    int *back = (int *)malloc((n + m) * sizeof(int));

    for(int i = 0;i < n + m;n++)
    {
        for(int j = 0;j < n;j++)
        {
            if(a[i] < min)
            {
                min = a[i];
                back[i] = 
            }
        }
        for(int k = 0;k < m;k++)
        {
            if(a[i] < min && back[])
            {
                min = b[i];
            }
        }
    }

    free(a);free(b);free(back);
    return 0;
}