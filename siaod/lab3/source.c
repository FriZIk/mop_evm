#include <iostream>
#include <locale.h>

using namespace std;

// Вариант #4

// Сортировка Шелла
/*
void ShellSort (int[] array, int size)               // * ∆k = (b∆k−1)/2  ∆0 = N
{
	int step, i, j, tmp;
	
	// Выбор шага
	for (step = size / 2; step > 0; step /= 2)
	    // Перечисление элементов, которые сортируются на определённом шаге
		for (i = step; i < size; i++) 
		    // Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
			for (j = i - step; j >= 0 && array[j] > array[j + step]; j -= step)
			{
				tmp = array[j];
				array[j] = array[j + step];
				array[j + step] = tmp;
			}
}
*/
void ShellSort(int *array)
{

}

//Сортировка вставками
/*
function insertionSort(a):
  for i = 1 to n - 1
    j = i - 1
    k = binSearch(a, a[i], 0, j)
    for m = j downto k
      swap(a[m], a[m+1])
*/
void InsertionSort(int *array)
{

}

int main()
{
    setlocale(LC_ALL,"Russian");
    /*
    Массив из 1000 первых натуральных чисел в порядке возрастания (пример уже отсортированного массива)
    Массив из 1000 первых натуральных чисел в порядке убывания (т.е пример массива, отсортированного наоборот)
    Не менее 4 сгенерированных массивов псевдослучайных чисел разного размера, от 100 до 100000 элементов
    */
   int
    int array1[1000];
    int array2[1000];
    int array3[];
    int n = 0;
    
    return 0;
}