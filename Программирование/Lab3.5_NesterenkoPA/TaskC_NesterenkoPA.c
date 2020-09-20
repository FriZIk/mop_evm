#include <stdio.h>

int main(void)
{
    const int n = 100;
    int a[n][n];

    int n1,m1;
    scanf("%d %d",&n1,&m1);
    for(int i = 0;i < n1;i++)
        for(int j =0;j<m1;j++)
            scanf("%d",&a[i][j]);

    int max = -1232321321;
    int max_indexs[n];
    int maxindex = 0;
    for(int i =0;i < n1;i++)
    {
        max = -1232321321;
        for(int j = 0;j < m1;j++)
        {
            if(max < a[i][j])max = a[i][j];
        }

        printf("%d ",max);

        for(int i =0;i < n1;i++)
        {
            for(int j = 0;j < m1;j++)
            {
                if(max == a[i][j]) 
                {
                    max_indexs[maxindex] = max;
                    maxindex++;
                }
            }
        }
        
    }
    for(int i = 0;i < maxindex;i++)printf("%d",max_indexs[i]);


    for(int i = 0;i < n1;i++)
    {
        for(int j =0;j<m1;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }    
    return 0;
}