#include <stdio.h>
#include <string.h>

// Список учеников
// 20:30 - 21:06 Решено 
int main()
{
    int n = 0;
    scanf("%d",&n);

    const int n1 = 1000;
    char str[n1][n1];    // Main string
    char str1[n1][n1];   // Final String
    int IndexI,IndexJ;
    for(int i = 0;i < n;i++)
    { 
        scanf("%s",str[i]);
        int len = strlen(str[i]);
        int StartIndex = 0,FinishIndex = 0;
        int max = -10;
        for(int j = 0;j < len;j++)
        {
            if(str[i][j] == ';')
            {
                FinishIndex = j;
                if(FinishIndex - StartIndex > max) max = j;
                //printf("%d %d ", StartIndex, FinishIndex);
                StartIndex = FinishIndex + 1;
            }
        }
        //printf("%d",max);

        for(int j = max-1;str[i][j] != ';';j--)
        {
            str1[IndexI][IndexJ] = str[i][j];
            IndexJ++; 
        }
        IndexI++;
        IndexJ = 0;
    }

    //Вывод ответа
    for(int i = 0;i < n;i++)
    {
        int len = strlen(str1[i]);
        for(int j = len;j >= 0;j--)
            printf("%c",str1[i][j]);
        if(i != n - 1)printf("\n");
    }
    return 0;
}