#include <stdio.h>

float func1(int a,int b)
{
    return (a + b)/2.0;
}

int main(void)
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%f\n",func1(a,b));
    return 0;
}