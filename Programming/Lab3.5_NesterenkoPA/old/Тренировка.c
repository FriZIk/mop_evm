#include <stdio.h>
#include <string.h>

void A() // Подмассив
{
    /*
    Пусть задан массив целых чисел а1, а2, ..., аn. 
    Назовем его подмассивом f(i,j) массив, составленный из чисел массива аi, ai+1,..., aj-1, aj. 
    Напишите программу, которая будет выводить подмассивы массива a.
    */

    const int n = 1000;
    long long int a[n];
    for(int i = 0;i < n;i++)a[i]=0;
    long long int n1;
    scanf("%d",&n1); // Размер массива
    for(long long int i = 0;i < n1;i++)scanf("%d",&a[i]);
    long long int m; //Кол-во подмассивов
    scanf("%d",&m);

    long long int b[n];
    long long int s = 0;
    for(long long int o = 0;o < m;o++)
    {
        long long int i,j;
        scanf("%d %d",&i,&j);
        b[s] = i;s++;
        for(int k = i;k < j;k++)
        {
            b[s] = a[k];
            s++;
        }
        b[s]=-2147483650;s++; 
    }

    for(long long int i = 0;i<s;i++)
    {
        if(b[i]!=-2147483650)printf("%d ",b[i]);
        else printf("\n");
    }
}

void B()// Похожие массивы
{
    /*
    Два массива называются похожими, если совпадают множества чисел, встречающихся в этих массивах.
    Требуется написать программу, которая определит: похожи ли два заданных массива.
    */
    const int k = 16000;
    int a[k],b[k];
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i = 0;i < m;i++)scanf("%d",&a[i]);
    for(int i = 0;i < n;i++)scanf("%d",&b[i]);
    int Count = 0;
    for(int i = 0;i < n;i++)
    {
        if(a[i] == b[i])
        {
            for(int j = i;a[i] == b[j];j++)
            {
                Count++;
            }
        }
    }
    
    if(Count == m || Count == n)printf("%d",1);
    else printf("%d",0);
}

void C()// Циклический сдвиг на один разряд вправо
{
    int const n = 100;
    int a[n];
    int n1;
    scanf("%d",&n1);
    for(int i = 0;i < n1;i++)scanf("%d",&a[i]);

    //Сдвиг вправо на 1 элемент
    int temp = a[n1 - 1];
    for(int i = n1;i > 0;i--)a[i] = a[i - 1];
    a[0]= temp;
    for(int i = 0;i < n1;i++)printf("%d ",a[i]);
}

void D() //Максимум и минимум
{
    const int n = 100;
    int a[n];
    int n1 = 0;
    scanf("%d",&n1);
    for(int i = 0;i < n1;i++)scanf("%d",&a[i]);

    int max = -1,min = 30001;
    int min_point = 0,max_point = 0;
    for(int i = 0;i < n1;i++)
    {
        if(a[i] < min)min = a[i];
        if(a[i] > max)max = a[i];
    }
    for(int i =0;i<n1;i++)
    {
        if(a[i] == max)max_point = i;
        if(a[i] == min)min_point = i;
    }

    int temp = a[max_point];
    a[max_point] = a[min_point];
    a[min_point] = temp;

    for(int i = 0;i < n1;i++)printf("%d ",a[i]);
}

void E()// Поиск соседей
{
    const int n=100;
    int n1;
    scanf("%d",&n1);
    int a[n];
    for(int i = 0;i < n1;i++)scanf("%d",&a[i]);

    for(int i = 1;i < n1-1;i++)
    {
        if(a[i] == a[i + 1] + a[i - 1])
        printf("%d ",a[i]);
    }
}

void F()// Кол-во элементов равных максимальному
{
    const int n=100;
    int n1;
    scanf("%d",&n1);
    int a[n];
    for(int i = 0;i < n1;i++)scanf("%d",&a[i]);

    int max = -1,Count = 0;
    for(int i = 0;i < n1;i++)if(a[i] > max)max = a[i];
    for(int i = 0;i < n1;i++)if(a[i] == max)Count++;
    printf("%d",Count);
}

void G()// Уникальные элементы
{
    const int n=100;
    int n1;
    scanf("%d",&n1);
    int a[n];
    for(int i = 0;i < n1;i++)scanf("%d",&a[i]);

    int b[n];
    for(int i = 0;i < n;i++)b[i] = 0;
    for(int i = 0;i < n1;i++)b[a[i]]++;
    for(int i = 0;i < n1;i++)
    {
        if(b[a[i]] == 1)printf("%d ",a[i]);
    }
    printf("\n");
}

void H()//Поворот массива право
{
    const int n=100;
    int n1;
    scanf("%d",&n1);
    int a[n][n];
    for(int i = 0;i < n1;i++)
    {
        for(int j = 0;j < n1;j++)
        {    
            scanf("%d",&a[i][j]);
        }
    }

    int a1[n][n];
    int tempn1 = n1;
    int l = 0,k = 0;

    while(n1 > 0)
    {
        l = 0;
        for(int i = 0;i < tempn1;i++,l++)
        {
            a1[l][k] = a[i][n1-1];
        }
        n1--;k++;
    }

    //Финальный вывод
    for(int i = l-1;i >= 0;i--)
    {
        for(int j = k-1;j >= 0;j--)
        {
            printf("%d ",a1[j][i]);
        }
        printf("\n");
    }
}

void I()//Сумма чисел в массиве
{
    int i,j;//Искомые
    const int n = 100000;
    int a[n];
    int n1;// Реальные размеры
    scanf("%d",&n1);
    for(int i = 0;i < n1;i++)scanf("%d",&a[i]);

    int maxSum = -1221321;
    int Sum = 0;
    for(int i = 0;i < n1 - 1;i++)
    {
        Sum = Sum + a[i];
        for(int j = i + 1;j < n1;j++)
        {
            Sum = Sum + a[j]; 
        }
        if(Sum > maxSum)maxSum = Sum;
        Sum = 0;
    }
    printf("%d\n",maxSum); //Не доделал это уже пипец просто я помираю
}

int main()
{
    while(1)
    {
        int a;
        printf("Номер программы:");
        scanf("%d",&a);
        switch(a)
        {
            case 1:A();break;
            case 2:B();break;
            case 3:C();break;
            case 4:D();break;
            case 5:E();break;
            case 6:F();break;
            case 7:G();break;
            case 8:H();break;
            case 9:I();break;
            default:printf("Неизветсная команда!!!\n");break;
        }
    }
    return 0;
}