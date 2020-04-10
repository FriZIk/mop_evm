#include <stdio.h>

int factorial(int a)
{
    if(a == 1)return 1;
    return a * factorial(a-1);
}
// Переделать лучше 
int main()
{
    for(int i = 0;i < 2;i++)printf("%lld\n",factorial(i));
    return 0;
}