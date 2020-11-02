#include <stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int n = 1000;
    int n1;
    scanf("%d",&n1);
    int a[n];
    for(int i = 0;i < n1;i++)scanf("%d",&a[i]);
    
    for(int i = 0;i < n1-1;i++)
        for(int j = i + 1;j < n1;j++)
            if(a[i] < a[j])swap(&a[i],&a[j]);

    for(int i = 0; i < n1;i++)printf("%d ",a[i]);
}