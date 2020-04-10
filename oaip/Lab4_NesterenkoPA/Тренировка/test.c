#include <stdio.h>

void func(int *a,int n1)
{
    for(int i = 0;i < n1;i++)
    {
        if(a[i] < 0) a[i] = -1;
        if(a[i] > 0) a[i] = 1;
    }
}

int main(void)
{
    const int n = 10000;
    int a[n];
    int n1;
    scanf("%d",&n1);
    for(int i = 0;i < n1;i++)scanf("%d",&a[i]);
    func(a,n1);
    for(int i = 0;i < n1;i++)printf("%d ",a[i]);
    return 0;
}


/*#include <stdio.h>

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
}
int main(void)
{
    int n = 100;
    int ar[n];
    int n1;
    scanf("%d",&n1);
    for(int i = 0;i < n1;i++)scanf("%d",&ar[i]);

    for(int i = 0;i < n1-1;i++)//Отсортировали массив 
    {
        for(int j = i + 1;j < n1;j++)
        {
            if(ar[i]>ar[j])
            {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp; 
            }
        }
    }

    int result = B(ar[0],ar[1]);
    for(int i = 2;i < n1;i++)
    {
        result = B(result,ar[i]);
    }
    printf("%d",result);
    return 0;
}*/