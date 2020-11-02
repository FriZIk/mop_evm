#include <stdio.h>
#include <stdlib.h>

void WriteFile()
{

}

int ReadFile(FILE *file,int count)
{
    fscanf(file,"%d",&count);
    return count; 
}

int main()
{
    FILE *file = fopen("input1.txt","rt");
    int count = 0;
    count = ReadFile(file,count);

    int *array = (int*)malloc(count * sizeof(int)); 

    for(int i = 0;i < count;i++)
    {
        array[i] = ReadFile(file,count);
        printf("%d ",array[i]);
    }
    fclose(file);
    return 0;
}