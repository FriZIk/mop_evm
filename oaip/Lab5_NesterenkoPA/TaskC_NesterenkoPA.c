/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: Тренировка
Задание: A - Сумма двух
Дата: 21.11.2019
*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file = fopen("input.txt", "rt");// Поток откртия файла на чтение
    int n = 1000;
    char str[n];
    //fgets(str,n,file);

    int ic;
    int len = 0;
    while((ic = fgetc(file)) != EOF)
    {
        str[len] = (char)ic;
        len++;
    }   
    for(int i = 0;i < len;i++)printf("%c",str[i]);
    fclose(file);

    for(int i = 0;i < len;i++)
    {
    }

    printf("\n");
    return 0;
}