#include <stdio.h>

int main()
{
    int n1,m1;
    const int n = 100,m = 10000;
    int a[n][m];
    scanf("%d %d",&m1,&n1);
    printf("\n");

    for(int i = 0;i < n1;i++)
        for(int j = 0;j < m1;j++)
            scanf("%d",&a[i][j]);
       
    printf("\n");
    // Находим минимумы строк
    int aMin[n][n];
    int count = 0;
    int min = 10001,mini,minj;
    for(int i = 0;i < n1;i++)
    {
        for(int j = 0;j < m1;j++)
        {
            if(a[i][j] < min)
            {
                min = a[i][j];
                mini = i;
                minj = j;
            }
        }
        aMin[0][i] = mini;
        aMin[1][i] = minj;
        min = 10001;
    }
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < n1;j++)printf("%d ",aMin[i][j]);
        printf("\n");
    }
    printf("\n \n");

    // Находим максимумы столбцов
    int aMax[n][n];
    int max = -100001,maxi,maxj;
    for(int i = 0;i < m1;i++)
    {
        for(int j = 0;j < n1;j++)
        {
            if(a[j][i] > max)
            {
                max = a[j][i];
                maxi = i;
                maxj = j;
            }
        }
        aMax[0][i] = maxj;
        aMax[1][i] = maxi;
        max = -100001; 
    }

    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < m1;j++)printf("%d ",aMax[i][j]);
        printf("\n");
    }
    printf("\n");

    for(int i = 0;i < n1;i++)
    {
        if(aMax[0][i] == aMin[0][i] && aMax[1][i] == aMin[1][i])
            printf("%d %d",aMax[0][i],aMax[1][i]);
    }
    printf("\n");
    return 0;
}