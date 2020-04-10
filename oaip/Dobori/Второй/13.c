/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: E. Список учеников
Дата: 28.01.2020
*/

#include <stdio.h>
#include <string.h>

int main()
{
    const int N1 = 51,N2 = 101;
    int n = 0;
    scanf("%d",&n);
    char str[51][101];

    for(int i = 0;i < n;i++)
        scanf("%s",&str[i]);
    int len[N1];
    for(int i = 0;i < n;i++)
        len[i] = strlen(str[i]); 

    printf("\n");
    int CountOfWords = 0;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < len[i];j++)
            if(str[i][j] == ';')CountOfWords++;

    CountOfWords = CountOfWords + 1;

    char str1[N1][N2];
    int n1= 0,n2 = 0;

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < len[i];j++)
        {
            if(str[i][j] == ';')
            {
                n1++;
                printf("\n");
            }
            else 
            {
                str1[n1][n2] = str[i][j];
                n2++;
                printf("%c",str[i][j]);
            }
            n1++;
            n2 = 0;
        }
    }
    printf("\n\n");
    for(int i = 0;i < n1;i++)
        printf("%s\n",str1[i]);
    return 0;
}