#include <stdio.h>

int sum(int a,int b,int temp_a) // Нахождение суммы 2 чисел рекурсивно испольхзу только +-1
{
    if(a < b)sum(a + 1,b),temp_a;
    else return a;

}

int main(void)
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",sum(a,b,a));
    return 0;
}
