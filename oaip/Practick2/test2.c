#include <stdio.h>

int main()
{
    const int n = 11;
    char str[n];
    fgets(str,n,stdin);
    int len = 0;char *a = str;
    
    int c =0;int pow = 1;

    for(a;*a;a++)
    {
        str[len] = str[len] - 65;
        len++;
    }

    for(int i = len - 1;i>=0;i--)
    {
        c = c + str[i] * pow;
        pow = pow * 26;
    }

    printf("%d\n",pow);
    return 0;
}