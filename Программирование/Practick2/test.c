#include <stdio.h>

int main()
{
    const int n = 256;
    char str[n];
    fgets(str, 256, stdin);
    char *a = str;

    char symbol;
    scanf("%c",&symbol);

    int count=0;int triger = 0;int pomogite = 0;
    for(a;*a;a++,count++)
    {
        if(*a == symbol && triger == 0)
        {
            pomogite = triger + 1;
        }
    }
    if(count != 1)printf("%d",pomogite);
    else printf("%d",0);
    return 0;
}