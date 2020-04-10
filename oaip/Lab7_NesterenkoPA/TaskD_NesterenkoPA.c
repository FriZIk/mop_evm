/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: E. D. Количество вхождений символов
Дата: 14.12.2019
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int n,m,a;
    scanf("&d &d &d",&n,&m,&a);
    // 5 * 6 = 30 30 - 2 * 5 + 6 * 2 = 18 18 / 2  = 9
    // 5 * 6 = 30 30 - 2 * 5 + 6 * 2 = 18 18 / 5 

    if((n * m - 2 *(n + m)) % a == 0)printf("YES");
    else printf("NO");
    return 0;
}
/*const int n = 102;
    char str[n];
    fgets(str,n,stdin);
    int len = strlen(str);
    char str1[n];
    int triger = 0,counter = 0;

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(str[i] != str[j] && i != j)triger = 1;
        }
        if(triger == 0)
        {
            str1[counter] = str[i];
            counter++;
        }
    }

    for(int i = 0;i < counter;i++)
        printf("%c\n",str[i]);
    return 0;*/