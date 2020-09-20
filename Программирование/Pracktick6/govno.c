#include <stdio.h>
#include <string.h>

int main()
{
    const int n1 = 100;
    char str[n1],n,m;
    fgets(str,n1,stdin);
    scanf("%c %c",&n,&m);
    int len = strlen(str);
    for(int i = 0;i < len;i++)
        if(str[i] == n)str[i] = m;
    fputs(str,stdout);
    return 0;
}