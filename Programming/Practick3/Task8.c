#include <stdio.h>

void EnterArray(int n1,int n2,int *a)
{
    for(int i = 0;i < 4;i++)
    {
        scanf("%d",(a+i));
    }
    printf("%d %d",a[1],a[0])
}


int main()
{
    const n = 100;
    int a[n][n];
    int n1,n2;
    scanf("%d %d",&n1,&n2);
   
    EnterArray(n1,n2,*a);

    for(int i = 0;i < n1;i++)
    {
        for(int j = 0;j < n2;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}