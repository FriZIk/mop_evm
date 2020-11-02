/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: E - Весы ИИ
Дата: 19.12.2019
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int n1 = 18,m1 = 18;
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n1][m1];
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            a[i][j] = 1;

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(i == 0 || j == 0)
                a[i][j] = 1;
            else
            {
                a[i][j] = a[i][j - 1] + a[i-1][j]; 
            }
            
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            printf("%-3d",a[i][j]);
        }
        if(i != n-1)printf("\n");
    }
    return 0;
}

/*
 for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(i == n - 1 && j == m - 1)printf("%d",a[i][j]);
            else printf("%-2d ",a[i][j]);
        }
        if(i != n-1)printf("\n");
    }
    return 0;
*/
