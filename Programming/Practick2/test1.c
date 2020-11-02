#include <stdio.h>

int main()
{
    const int n = 40001;
    char str[n];
    fgets(str,n,stdin);
    char *a = str;int len = 0;
    for(a;*a;a++,len++);
    printf("%d",len);
 
    int count =0 , lenght = 0;
    const int n1 = 20001;
    int lenghts[n1];
    char s[n];

    for(int i = 0;i < len;i++)
    {
        if(str[i] != ' ' && (i==0 || str[i] == ' '))
        {
            S[count] = i;
            lenght++;   
        }
    }

    return 0;
}