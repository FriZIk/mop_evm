#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0;
    scanf("%d",&N);
    int **a = (int**)calloc(N,sizeof(int*));
    
    for(int i = 0;i < N;i++)
        a[i] = (int*)calloc(N,sizeof(int));
    
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
            printf("%X ",&a[i][j]);
        printf("\n");
    }
    return 0;
}