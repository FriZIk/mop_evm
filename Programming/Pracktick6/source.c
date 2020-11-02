/*
Условие :
Петя попросил каждого своего одноклассника составить список подарков, которые тот хочет получить на Новый год. 
Этот список записывается в виде одной непустой строки с названиями подарков. Помоги 
Пете понять, сколько человек оставили свои пожелания и сколько подарков захотел получить каждый из них. 
Даже если названия подарков совпадают, они считаются разными подарками.

Входные данные :
В каждой строке длиной не более N символов (1≤N≤100)
с помощью маленьких латинских букв записаны разделенные пробелом названия подарков, 
которые заказал один одноклассник. Всего строк не более 1000, при этом каждый одноклассник заполнил только одну строку.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file = fopen("input.txt","rt");
    char str[100];
    fgets(str,100,file);
    printf("Строка:%s\n",str);
    printf("Первый EOF:%d\n",feof(file));

    fgets(str,100,file);
    int len = strlen(str);
    printf("Длина строки:%d\n",len);

    char a;
    fread(&a,1,1, file);
    printf("Вывод fread():%d\n",a);
    printf("Второй EOF:%d\n",feof(file));

    int n = ftell(file);
    printf("Вывод ftell():%d\n",n);
    
    fclose(file);
    return 0;
}