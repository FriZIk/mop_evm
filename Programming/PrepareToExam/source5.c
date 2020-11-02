#include <stdio.h>
#include <string.h>

int SearchWords(char *str,int FirstSymbol,int LastSymbol,int count,int *StartNewWord)
{
   for(int i = FirstSymbol;i < LastSymbol;i++)
    {
        if(str[i] == ' ' && *StartNewWord == 0)
        {
            *StartNewWord = 1;
            count++;
        }
        if(str[i] != ' ' && *StartNewWord == 1)
        {
            *StartNewWord = 0;
        }
    }
    return count;
}

// Подсчёт количества строк в строке
int main()
{
    const int n = 100;
    char str[n];
    fgets(str,n,stdin);
    int len = strlen(str);

    // Отсекание лишних пробелов
    int FirstSymbol = 0;
    int LastSymbol = len - 2;
    for(FirstSymbol;str[FirstSymbol] == ' ';FirstSymbol++);
    printf("%d ",FirstSymbol);
    for(LastSymbol;str[LastSymbol] == ' ';LastSymbol--);
    printf("%d ",LastSymbol);

    // Основной блок программы
    int StartNewWord = 0;
    int count;
    if(LastSymbol < 0)count = 0;
    else count = 1;
    count = SearchWords(str,FirstSymbol,LastSymbol,count,&StartNewWord);
    printf("\nКоличество слов(2 способ):%d\n",count);
    return 0;
}