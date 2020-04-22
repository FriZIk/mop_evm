#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

// Вариант #4
//void BunSearch(); // Бинарный поиск
//void InsertionSort(int *array); //Сортировка вставками
void ShellSort(int *array,int n); // Сортировка Шелла
void PrintArray(int *array,int n); // Вывод массива на экран
void FullArray(int *array1,int *array2,int *array3,int *array4,int *array5,int *array6,int n3,int n4,int n5,int n6); 
void InitArrays(int *array1,int *array2,int *array3,int *array4,int *array5,int *array6,int n12,int n3,int n4,int n5,int n6,int MaxLimit); // Инициалихзация массивов

int main()
{
    setlocale(LC_ALL,"Russian");
    srand(time(NULL));
    const int n12 = 1000; 
    int array1[n12]; //Массив из n12 первых натуральных чисел в порядке возрастания (пример уже отсортированного массива)
    int array2[n12]; // Массив из n12 первых натуральных чисел в порядке убывания (т.е пример массива, отсортированного наоборот)

    // 4 сгенерированных массива псевдослучайных чисел разного размера, от 100 до 100000 элементов
    const int n3 = 100,n4 = 1000,n5 = 10000,n6 = 100000;
    int array3[n3],array4[n4],array5[n5],array6[n6];
    int MaxLimit = 100000; // Предел генерации случайных величин

    //Инициализция массивов
    InitArrays(array1,array2,array3,array4,array5,array6,n12,n3,n4,n5,n6,MaxLimit);
    // Не хочется 'сорить' в мейне так что отправля. массивы в промежуточную функцию'
    FullArray(array1,array2,array3,array4,array5,array6,n3,n4,n5,n6);

    printf("\nВведите команду (1 - Сортировка Шелла,2 - сортировка бинарными вставками):");
    int choose;
    scanf("%d",&choose);
    switch(choose)
    {
      case 1:
        // Запускаем сортировку шелла для всех массивов (Yработает не правильно, проверить!!!)
        ShellSort(array1,n12);
        ShellSort(array2,n12);
        ShellSort(array3,n3);
        ShellSort(array4,n4);
        ShellSort(array5,n5);
        ShellSort(array6,n6);
        printf("Отсортированные массивы(Сортировкой Шелла):\n");
        FullArray(array1,array2,array3,array4,array5,array6,n3,n4,n5,n6);
        scanf("%d",&choose);
      break;
      case 2:
        // Запускаем сортировку бинарными вставками для всех массивов
        InsertionSort(array1,n12);
        InsertionSort(array2,n12);
        InsertionSort(array3,n3);
        InsertionSort(array4,n4);
        InsertionSort(array5,n5);
        InsertionSort(array6,n6);
        printf("Отсортированные массивы(Сортировкой Шелла):\n");
        FullArray(array1,array2,array3,array4,array5,array6,n3,n4,n5,n6);
        scanf("%d",&choose);
      break;
      default:printf("Неизвестная комада!!!");
    }
    return 0;
}

// Функцция для инициализации начальных данных в массиве
void InitArrays(int *array1,int *array2,int *array3,int *array4,int *array5,int *array6,int n12,int n3,int n4,int n5,int n6,int MaxLimit)
{
    for(int i = 0;i < n12;i++)array1[i] = i;
    for(int i = n12;i >= 0;i--)array2[i] = n12 - i;
    for(int i = 0;i < n3;i++)array3[i] = rand() % MaxLimit;
    for(int i = 0;i < n4;i++)array4[i] = rand() % MaxLimit;
    for(int i = 0;i < n5;i++)array5[i] = rand() % MaxLimit;
    for(int i = 0;i < n6;i++)array6[i] = rand() % MaxLimit;
}

// Промежуточная функция для вывода
void FullArray(int *array1,int *array2,int *array3,int *array4,int *array5,int *array6,int n3,int n4,int n5,int n6) 
{
  int MaxLimitShow = 10;
  printf("Массив из 1000 первых натуральных чисел в порядке возрастания:");
  for(int i = 0;i < MaxLimitShow;i++)
  printf("%d ",array1[i]);
    
  printf("\nМассив из 1000 первых натуральных чисел в порядке убывания:");
  for(int i = 0;i < MaxLimitShow;i++)
  printf("%d ",array2[i]);

  PrintArray(array3,n3);
  PrintArray(array4,n4);
  PrintArray(array5,n5);
  PrintArray(array6,n6);
}

// Основной вывод
void PrintArray(int *array,int n)
{
  if(n != 1000)
  {
  int MaxLimitShow = 10; // Вывод первых MaxLimitShow цифр массива 
  printf("\nCгенерированных массива псевдослучайных чисел(%d): ",n);
    for(int i = 0;i <= MaxLimitShow;i++)
      printf("%d ",array[i]);
  }
}

// Сортировка Шелла
void ShellSort(int *array,int n) 
{
  for(int step = n / 2;step > 0;step /= 2)
  {
    for(int i = step;i < n;i++)
    {
      for(int j = i - step;j >=0 && array[j] > array[j + step];j -= step)
      {
        int temp = array[j];
        array[j] = array[j + step];
        array[j + step] = temp;
      }
    }
  }
}

// Бинарный поиск
int BinSearch(int *array,int start, int finish, int target)
{
  int midd = 0;
  while (1)
  {
    midd = (start + finish) / 2;
    
    if (target < array[midd])
      finish = midd - 1;      
    else if (target > array[midd])  
      start = midd + 1;   
    else                      
      return midd;           
    
    if (start > finish) // на случай если что-то пошло не так
      return -1;
  }
}

//Сортировка вставками (без бинарных)
void InsertionSort(int *array,int n)
{
  for(int i = 1;i < n - 1;i++)
  {
    int j = i - 1;
    while(j >= 0 && array[j] > array[j + 1])
    {
      int temp = array[j];
      array[j] = array[j + 1];
      array[j + 1] = temp;
      j--; 
    }
  }
}

// Сортировка бинарными вставками
/*void InsertionSort(int *array,int n) //Сортировка вставками
{
  for(int i = 1;i < n - 1;i++)
  {
    int j = i - 1;
    int k = BinSearch(array,0,j,array[i]); 
    for(int m = j;j > k;j++)
    {
      int temp = array[m];
      array[m] = array[m + 1];
      array[m + 1] = temp;
    }
  }
}*/