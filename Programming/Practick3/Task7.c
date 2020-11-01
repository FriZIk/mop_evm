#include <stdio.h>

int step(int a,int n,int a1)
{
    if(n == 1)return a;
    else return step(a*a1,n-1,a1);
}

int main()
{
    int a,n;
    scanf("%d %d",&a,&n);
    int a1 = a;
    
    printf("%d\n",step(a,n,a1));
    return 0;
}