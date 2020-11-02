#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// функция сравнения введённой строки с шаблоном 11...111-111...1+11..1
int CheckTemplate(char *str,int len) 
{
    int i = 0;
    int temp_i = i;
    int lenCounter1 = 0,lenCounter2 = 0;
    for(i;str[i] == '1';i++,lenCounter1++)
        printf("%c",str[i]);
    if(temp_i != i)
    {
        if(str[i] != '-')return 0; // Строка не подходит под шаблона
        else
        {
            printf("%c",str[i]);
            i++; 
            int temp_i = i; 
            for(i;str[i] == '1';i++,lenCounter2++)
                printf("%c",str[i]);
            if(temp_i == i || lenCounter1 <= lenCounter2) return 0; // Строка не подходит, так как после минуса сразу идёт плюс
            else
            {
                if(str[i] != '+')return 0; // Строка не подходит под шаблона
                else
                {
                    printf("%c",str[i]);
                    i++;
                    temp_i = i;
                    for(i;str[i] == '1';i++)
                        printf("%c",str[i]);
                    if(temp_i == i)return 0; // Строка не подходит под шаблона
                    else return 1;
                }
                
            }
        }
    }
    else return 0; // Строка не подходит, так как нет единиц    
}

int main()
{
    const int n = 100;
    char str[n];
    scanf("%s",str);
    int len = strlen(str);
    if(CheckTemplate(str,len) == 1)printf("YES");
    else printf("NO");
    return 0;
}