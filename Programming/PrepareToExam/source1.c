#include <stdio.h>
#include <string.h>

// Непереносимость fu
// Забыл засечь где-то примерно минут 20, наверное
int main()
{   
    const int n = 255;
    char str[n];
    fgets(str,n,stdin);

    int len = strlen(str);
    
    int i = 0;
    while(i != len)
    {
        if(str[i] == 'f' && str[i + 1] == 'u')
        {
            for(int j = i;j < len;j++)
            {
                str[j] = str[j + 2];
                str[j + 2] = "";
            }
        }
        if(str[i] == 'u' && str[i - 1] == 'f')
        {
            for(int j = i;j < len;j++)
            {
                str[j - 1] = str[j + 1];
                str[j + 1] = "";
            }
        }
        else i++;
    }
    
    len = strlen(str);
    printf("%s",str);
    return 0;
}