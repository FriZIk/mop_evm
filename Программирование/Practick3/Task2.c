#include <stdio.h>

void func(int *a,int n1)
{
    for(int i = 0;i < n1;i++)
    {
        if(a[i] < 0) a[i] = -1;
        if(a[i] > 0)a[i] = 1;
    }
}

int main(void)
{
    const int n = 10000;
    int a[n];
    int n1;
    scanf("%d",&n1);
    for(int i = 0;i < n1;i++)scanf("%d",&a[i]);
    func(a,n1);
    for(int i = 0;i < n1;i++)printf("%d ",a[i]);
    return 0;
}