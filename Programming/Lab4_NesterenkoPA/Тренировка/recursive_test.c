#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int n2 = 0;

void A(int *a,int n1)//Рекурсивный вывод массива
{
    printf("%d ",*a);
    if(n1 > n2) 
    {
        n2 = n2 + 1;
        A(a+1,n1);
    }
}
void A1()
{
    const int n = 1000; 
    int a[n];
    int i = 0;
    int n1 = 0 ;
    scanf("%d",&n1);
    for(int i = 0;i<n1;i++)scanf("%d",&a[i]);
    int *u = a; 
    A(u,n1 - 1);
}

int B(int a,int b)// Нахождение нод числа
{
    int temp = b;
    if(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
        B(a,b);
    }
    if(b == 0)return temp;
    return 0;//temp
}

void C()//говно не работает
{
    const int n = 30000;
    int a[n];
    for(int  i = 0;i < 30000;i++)a[i] = i + 1;
    int n1, a1[n];
    scanf("%d",&n1);
    for(int i = 0;i < n1;i++)scanf("%d",&a1[i]);

    int rezult1 = 1,first_triger = 0;
    for(int i = 0;i < n1;i++)
    {
        if(first_triger == 0)rezult1 = B(a1[i],a[i+1]);
        else rezult1 = B(rezult1,a1[i]);
        printf("%d ",rezult1);
    }
    printf("\n");
}

int D(int x1,int y1,int x2,int y2,int x3,int y3)//Периметр треугольника
{
    double len1,len2,len3;
    int cor = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    len1 = sqrt(cor);
    cor = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
    len2 = sqrt(cor);
    cor = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
    len3 = sqrt(cor);
    return len1 + len2 + len3;
}
void D1()
{
    int x1,y1,x2,y2,x3,y3;
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    printf("%f",D(x1,y1,x2,y2,x3,y3));
}

int E() // Рисование ёлочки
{
    while(1)
    {
        //Елочка
        const int n = 1000; 
        char a[n][n];
        int n1;
        scanf("%d",&n1);
        for(int i = 0;i < n1*2;i++)
            for(int  j = 0;j < n1*2;j++)
                a[i][j] = '.';

        int kek = (n1 + n1 -2)/2;// Находим центр
        for(int  i = 0; i < n1;i++)
        {   
            a[i][kek] = '*';
            for(int j = 0;j < i;j++)
            {
                a[i][kek - j - 1] = '*';
                a[i][kek + j + 1] = '*'; 
            }
        }

        for(int i = 0;i < n1;i++)
        {
            for(int j = 0;j < n1 * 2 -1 ;j++)
                printf("%c",a[i][j]);
            printf("\n");
        }
    }
}

int sort(int * a,int n)// Сортировка динамического массива
{
    for(int i = 0;i < n - 1;i++)
    {
        for(int j = i + 1;j < n;j++)
        {
            if(*(a + i) > *(a + j))
            {
                int temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}
void presotr()
{
    int n;
    scanf("%d",&n);
    int *a = (int*)malloc(n * sizeof(int));
    for(int i = 0;i < n;i++)scanf("%d",a + i);
    
    int * pr_a = a;
    sort(a,n);

    for(int i = 0;i < n;i++)printf("%d ",*(a + i));
}

int sum(int a,int b) // Нахождение суммы 2 чисел рекурсивно испольхзу только +-1
{
    if(a < b)sum(a + 1,b);
    else return a;
}

int main(void)
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",sum(a,b));
    return 0;
}

