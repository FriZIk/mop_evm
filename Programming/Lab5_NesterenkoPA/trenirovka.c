/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: Тренировка
Задание: A - Сумма двух
Дата: 21.11.2019
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>

void A()// Чтение и запись отдельных переменных в файла
{
    int a,b;
    scanf("%d %d",&a,&b);
    FILE *file = fopen("test.txt", "wt");// Поток открытия файла на запись
    fprintf(file,"%d",a+b);
    fclose(file); // Закрытие потока

    int result = 0;
    FILE *file1 = fopen("test.txt", "rt");// Поток откртия файла на чтение
    fscanf(file,"%d",&result);
    printf("Суммач:%d\n",result);
    fclose(file1);
}

void B() // Чтение и запись строк
{
    const n = 10000;
    char str[n];
    fgets(str,n,stdin);
    FILE *file = fopen("test.txt","wt");
    fputs(str,file); // Запись введённой строки в файл
    fclose(file);

    FILE *file1 = fopen("test.txt","rt");
    char str1[n];
    fgets(str1,n,file1);
    fputs(str,stdout); // Вывод полученной из файла строки
    fclose(file1);
}

void C() // Вывод слов с новой строки 
{
    const int n = 100000;
    char str[n];
    fgets(str,n,stdin);
    int len = strlen(str);
    int triger = 0;int trigerfirst = 0;

    FILE *file = fopen("test.txt","wt");
    for(int i = 0;i < len;i++)
    {
        if(isspace(str[i]) == 0)trigerfirst = 1;
        if(isspace(str[i]) != 0 && triger == 0 && trigerfirst == 1)
        {
            triger = 1;
            fprintf(file,"\n");// Записываем в файл пробел
            printf("\n");
        }
        if(isspace(str[i]) == 0)
        {
            triger = 0;
            fprintf(file,"%c",str[i]); // Либо не пробел
            printf("%c",str[i]); 
        }
    }
    fclose(file);
}

int main()
{
    // Тест с матрицей

    int n,m; // Размер массива
    scanf("%d %d",&n,&m);
    int *a = (int*)malloc(n * m * sizeof(int)); // создание динамической матрицы размеров: n X m
    
    int count = 1;
    for(int i = 0;i < n;i++)
    {    
        for(int j = 0;j < m;j++)
        {
            *(a + i*m + j) = count;
            count = count +1;
        }
    }
    FILE *file = fopen("test.txt","wt");
    
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
            fprintf(file,"%d ",a[i]);
        fprintf(file,"\n");
    }
    free(a);
    fclose(file);
    return 0;
}