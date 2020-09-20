#include <stdio.h>

int main(void)
{
    const int n = 1000;
    int a[n][n];

    int n1 = 0;
    scanf("%d",&n1);

    for(int i = 0;i < n1;i++)
        for(int j = 0;j < n1;j++)
            scanf("%d",&a[i][j]);


    

    for(int i =0;i < n1;i++)
    {
        for(int j = 0;j < n1;j++)
            printf("%d\n",a[i][j]);
    }   
    return 0;
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
        aMax[i][0] = maxj;
        aMax[i][1] = maxi;
        max = -100001; 
    }
}