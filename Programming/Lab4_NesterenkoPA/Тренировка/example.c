#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main()
{
  int *a;  // указатель на массив
  int i, j, n, m;
  system("chcp 1251");
  system("cls");
  printf("Введите количество строк: ");
  scanf("%d", &n);
  printf("Введите количество столбцов: ");
  scanf("%d", &m);
  // Выделение памяти
  a = (int*)malloc(n*m * sizeof(int));
  // Ввод элементов массива
  for (i = 0; i<n; i++)  // цикл по строкам
  {
    for (j = 0; j<m; j++)  // цикл по столбцам
    {
      printf("a[%d][%d] = ", i, j);
      scanf("%d", (a + i*m + j));
    }
  }
  // Вывод элементов массива
  for (i = 0; i<n; i++)  // цикл по строкам
  {
    for (j = 0; j<m; j++)  // цикл по столбцам
    {
      printf("%5d ", *(a + i*m + j)); // 5 знакомест под элемент массива
    }
    printf("\n");
  }
  free(a);
  getchar();   getchar();
  return 0;
}