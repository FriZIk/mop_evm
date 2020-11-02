#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    
    // Make matrix
    int **a = (int**)calloc(sizeof(int*),n);
    for(int i = 0;i < n;i++)
        a[i] = (int*)calloc(sizeof(int),n);

    // Initicializing
    int temp = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
            a[i][j] = temp + j + 1;
        temp = temp + n;
    }

    // Print Final Matrix;        
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
            printf("%-2.d ",a[i][j]);
        printf("\n");
    }

    //  Print in file
    FILE *file = fopen("output.txt","wt");
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
            fprintf(file,"%d ",a[i][j]);
        fprintf(file,"\n");
    }
    close(file);
    //Clear memory
    for(int i = 0;i < n;i++)
        free(a[i]);

    free(a);
    return 0;
}