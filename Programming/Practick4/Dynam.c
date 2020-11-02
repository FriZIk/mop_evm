#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int n1 = 3,m1 = 6;
    int m[n1][m1];
     for(int i = 0;i < n1;i++)
        for(int j = 0;j < m1;j++)
            m[i][j] = i*m1+j;

    for(int i = 0;i < n1;i++)
    {
        for(int j = 0;j < m1;j++)
            printf("%d ",(*(*(m+i)+j)));
        printf("\n");
    }

    printf("\n");

    for(int i = 0;i < n1;i++)
    {
        for(int j = 0;j < m1;j++)
            printf("%d ",*(m[0]+i*m1+j));
        printf("\n");
    }

    printf("\n");

    int n = 3,m3 = 6;
    int **m2 = (int **)malloc(sizeof(int*) * n);//Массив указателей
    for(int i = 0;i < n;i++)
        m2[i] = (int*) malloc(sizeof(int) * m3);

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m3;j++)
            m2[i][j] = i*m3+j;

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m3;j++)
            printf("%d ",(*(*(m2+i)+j)));
        printf("\n");
    }

    printf("\nВидишь не раотает вот так, с динамическим,а?Нравится тебе ?\n");

    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m3;j++)
            printf("%d ",*(m2[0]+i*m1+j));
        printf("\n");
    }
    
    // Освобождение памяти
    for(int i = 0;i < n;i++)
        free(m2[i]);
    free(m2);
    return 0;
}