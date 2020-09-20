/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: C - Строка на слова
Дата: 21.11.2019
*/
#include <stdio.h>

int main()
{
    const int n = 10000;
    int a[n];

    return 0;
}


/*int Droblenie(char *str,int len)// Функция дробления 
{   
    const int n = 1000;
    char real_str[n];
    int counter_real_str = 0;

    int triger_zeros = 0,triger_no_zeros = 0;
    for(int  i = 0;i < len;i++)
    {
        if(*(str + i) == ' ')
        {
            if(triger_zeros != 1)
            {
                if(triger_no_zeros != 0)//Чтобы вывод пробелов не повторялся
                {
                    real_str[counter_real_str] = '\n';counter_real_str++;
                    triger_zeros = 1;
                    triger_no_zeros = 0;
                }
            }
        }
        else 
        {
            real_str[counter_real_str] = *(str + i);counter_real_str++;
            if(triger_no_zeros == 0)
            {
                triger_no_zeros = 1;
            }
            triger_no_zeros = 1;//Найдено новое слово
            triger_zeros = 0;
        }
    }
    for(int i =0;i < counter_real_str;i++)
        *(str + i) = real_str[i];
    return counter_real_str;
}*/