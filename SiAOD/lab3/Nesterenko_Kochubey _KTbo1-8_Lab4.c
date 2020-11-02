#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>

// Вариант #4
double InsertionSort(int *array,int n,int *NumberOfAssignments,int *umberOfComparisons); //Сортировка вставками
double ShellSort(int *array,int n,int *NumberOfAssignments,int *NumberOfComparisons); // Сортировка Шелла
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

    FILE *out = fopen("output.txt","wt");
    int NumberOfComparisons = 0; // количество сравнений
    int NumberOfAssignments = 0; // количетсво присваиваний 
 double a;
    switch(choose)
    {
      case 1:
        // Запускаем сортировку шелла для всех массивов 
        fprintf(out,"Сортировка Шелла:\n");
        fprintf(out,"Время ушедшее на сорировку массва из %d элементов(по возратсанию):%f msec. Выполнено сравнений:%d. Выполнено присваиваний:%d\n",n12,ShellSort(array1,n12,&NumberOfAssignments,&NumberOfComparisons),NumberOfComparisons,NumberOfAssignments);
        fprintf(out,"Время ушедшее на сорировку массва из %d элементов(по убыванию):%f msec. Выполнено сравнений:%d. Выполнено присваиваний:%d\n",n12,ShellSort(array2,n12,&NumberOfAssignments,&NumberOfComparisons),NumberOfComparisons,NumberOfAssignments);
        fprintf(out,"Время ушедшее на сорировку массва из %d элементов:%f msec. Выполнено сравнений:%d. Выполнено присваиваний:%d\n",n3,ShellSort(array3,n3,&NumberOfAssignments,&NumberOfComparisons),NumberOfComparisons,NumberOfAssignments);
        fprintf(out,"Время ушедшее на сорировку массва из %d элементов:%f msec. Выполнено сравнений:%d. Выполнено присваиваний:%d\n",n4,ShellSort(array4,n4,&NumberOfAssignments,&NumberOfComparisons),NumberOfComparisons,NumberOfAssignments);
        fprintf(out,"Время ушедшее на сорировку массва из %d элементов:%f msec. Выполнено сравнений:%d. Выполнено присваиваний:%d\n",n5,ShellSort(array5,n5,&NumberOfAssignments,&NumberOfComparisons),NumberOfComparisons,NumberOfAssignments);
        fprintf(out,"Время ушедшее на сорировку массва из %d элементов:%f msec. Выполнено сравнений:%d. Выполнено присваиваний:%d\n",n6,ShellSort(array6,n6,&NumberOfAssignments,&NumberOfComparisons),NumberOfComparisons,NumberOfAssignments);

        printf("Отсортированные массивы(Сортировкой Шелла):\n");
        FullArray(array1,array2,array3,array4,array5,array6,n3,n4,n5,n6);
        /*fprintf(out,"\nОтсортированный массив методом шелла:\n");
        for(int i = 0;i < n3;i++)
        {
          if(i%10 == 0 && i != 0)fprintf(out,"%d\n",array3[i]);
          else fprintf(out,"%d ",array3[i]);
        }*/
        fclose(out);
      break;
      case 2:
        // Запускаем сортировку бинарными вставками для всех массивов
        a = InsertionSort(array1,n12,&NumberOfComparisons,&NumberOfAssignments);
        fprintf(out,"Сортировка бинарными вставками:\n");
        fprintf(out,"Время ушедшее на сорировку массва из %d элементов(по возратсанию):%f msec. Выполнено сравнений:%d. Выполнено присваиваний:%d\n",n12, a,NumberOfComparisons,NumberOfAssignments);
        fprintf(out,"Время ушедшее на сорировку массва из %d элементов(по убыванию):%f msec. Выполнено сравнений:%d. Выполнено присваиваний:%d \n",n12, InsertionSort(array2,n12,&NumberOfComparisons,&NumberOfAssignments),NumberOfComparisons,NumberOfAssignments);
        fprintf(out,"Время ушедшее на сорировку массва из %d элементов:%f msec. Выполнено сравнений:%d. Выполнено присваиваний:%d\n",n3,InsertionSort(array3,n3,&NumberOfComparisons,&NumberOfAssignments),NumberOfComparisons,NumberOfAssignments);
        fprintf(out,"Время ушедшее на сорировку массва из %d элементов:%f msec. Выполнено сравнений:%d. Выполнено присваиваний:%d\n",n4,InsertionSort(array4,n4,&NumberOfComparisons,&NumberOfAssignments),NumberOfComparisons,NumberOfAssignments);
        fprintf(out,"Время ушедшее на сорировку массва из %d элементов:%f msec. Выполнено сравнений:%d. Выполнено присваиваний:%d\n",n5,InsertionSort(array5,n5,&NumberOfComparisons,&NumberOfAssignments),NumberOfComparisons,NumberOfAssignments);
        fprintf(out,"Время ушедшее на сорировку массва из %d элементов:%f msec. Выполнено сравнений:%d. Выполнено присваиваний:%d\n",n6,InsertionSort(array6,n6,&NumberOfComparisons,&NumberOfAssignments),NumberOfComparisons,NumberOfAssignments);

        printf("Отсортированные массивы(Сортировкой Шелла):\n");
        FullArray(array1,array2,array3,array4,array5,array6,n3,n4,n5,n6);
      break;
      default:printf("Неизвестная комада!!!");break;
    }
    return 0;
}

// Функцция для инициализации начальных данных в массиве
void InitArrays(int *array1,int *array2,int *array3,int *array4,int *array5,int *array6,int n12,int n3,int n4,int n5,int n6,int MaxLimit)
{
    for(int i = 0;i < n12;i++)array1[i] = i;
    for(int i = n12-1;i >= 0;i--)array2[i] = n12 - i;
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
double ShellSort(int *array,int n,int *NumberOfAssignments,int *NumberOfComparisons) 
{
  *NumberOfAssignments = 0; // количетсво присваиваний 
  *NumberOfComparisons = 0; // количество сравнений
  clock_t start = clock();
  for(int step = n / 2;step > 0;step /= 2,*NumberOfAssignments = *NumberOfAssignments + 1,*NumberOfComparisons = *NumberOfComparisons + 1)
  {
    for(int i = step;i < n;i++,*NumberOfAssignments = *NumberOfAssignments + 1,*NumberOfComparisons = *NumberOfComparisons + 1)
    {
      for(int j = i - step;j >=0 && array[j] > array[j + step];j -= step,*NumberOfAssignments =  * NumberOfAssignments + 5,*NumberOfComparisons = *NumberOfComparisons + 1)
      {
        int temp = array[j];
        array[j] = array[j + step];
        array[j + step] = temp;
      }
    }
  }
  clock_t end = clock();
  return ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
}

double InsertionSort(int *array,int n,int *NumberOfAssignments,int *NumberOfComparisons)
{
  *NumberOfAssignments = 0; // количетсво присваиваний 
  *NumberOfComparisons = 0; // количество сравнений
  int key = 0, lo = 0, hi = 0, mid = 0;
	clock_t start = clock();
  for (int i = 1; i < n; i++,*NumberOfAssignments = *NumberOfAssignments + 2,*NumberOfComparisons = *NumberOfComparisons + 1)
	{
    *NumberOfComparisons = *NumberOfComparisons + 1;
		if (array[i - 1] > array[i])
		{
      *NumberOfComparisons = *NumberOfComparisons + 1;
			key = array[i];
			lo = 0, hi = i - 1;
      *NumberOfAssignments = *NumberOfAssignments + 2;
			do 
			{
				mid = (lo+hi)/ 2;
        *NumberOfAssignments = *NumberOfAssignments + 1;
				if (key < array[mid])	
        {
          *NumberOfAssignments = *NumberOfAssignments + 1;
          *NumberOfComparisons = *NumberOfComparisons + 1; 
          hi = mid;
        }
        else 
        {
          lo = mid + 1;
          *NumberOfAssignments = *NumberOfAssignments + 1;
          *NumberOfComparisons = *NumberOfComparisons + 1; // do while
        }
			} while (lo < hi);
			for (int j = i - 1; j >= lo; j--, *NumberOfAssignments = *NumberOfAssignments + 2, *NumberOfComparisons = *NumberOfComparisons + 1)
			{
				array[j + 1] = array[j];	
        *NumberOfAssignments = *NumberOfAssignments + 1;
			}
			array[lo] = key;
      *NumberOfAssignments = *NumberOfAssignments + 1;
		}		
	}
  clock_t end = clock();
  return ((double)(end - start) / CLOCKS_PER_SEC) * 1000;;
}