/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: B. Банкнота раздора
Дата: 25.01.2020
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[10];
    scanf("%s",str);
    int len = strlen(str);
    int a = atoi(str);
    if(str[0] == str[len-1] && a%3 == 0 && str[len-2] == str[len-1] || a%2 == 0)printf("YES");
    else printf("NO");
    return 0;
}
