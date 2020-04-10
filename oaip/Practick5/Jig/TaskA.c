#include <stdio.h>
#include <stdlib.h>

struct zumer
{
    short H;
    short M;
    short S;
    double value;
};


/*
80
4
93 JhpS CzTusjdifolp 100 SsdfsdfsdfPromSsaddada
73 JhpS CzTusjdifolp 100 SsdfsdfsdfPromSsaddada
63 JhpS CzTusjdifolp 100 SsdfsdfsdfPromSsaddada
24 JhpS CzTusjdifolp 100 SsdfsdfsdfPromSsaddada

*/

int main()
{
    FILE *file = fopen("input.txt","rt");
    struct zumer *Z;
    
    /*printf("%d\n",sizeof(Z.H));
    printf("%d\n",sizeof(Z.M));
    printf("%d\n",sizeof(Z.S));
    printf("%f\n",sizeof(Z.value));
    printf("%d\n",sizeof(Z));*/

    int ZamerCount = 0;
    if(file != 0)
    {
        fscanf(file,"%d",&ZamerCount);
        Z = (struct zumer*)malloc(ZamerCount * sizeof(struct zumer));
        for(int i = 0;i < ZamerCount;i++)
        {
            fscanf(file,"%d:%d:%d %lf",&Z[i].H,&Z[i].M,&Z[i].S,&Z[i].value);
            printf("%d:%d:%d %0.1lf\n",Z[i].H,Z[i].M,Z[i].S,Z[i].value);
        }
    }

    struct zumer temp;
    for(int i = 0;i < ZamerCount - 1;i++)
    {
        for(int j = i + 1;j < ZamerCount;j++)
        {
            if(Z[i].value > Z[j].value)
            {
                temp = Z[i];
                Z[i] = Z[i+1];
                Z[i+1] = temp;
            }
        }
    }
    printf("\n");
    for(int i = 0;i < ZamerCount;i++)
        printf("%d:%d:%d %0.1lf\n",Z[i].H,Z[i].M,Z[i].S,Z[i].value);

    for(int i = 0;i < ZamerCount - 1;i++)
    {
        for(int j = i + 1;j < ZamerCount;j++)
        {
            if(Z[i].H > Z[j].H || Z[i].H == Z[j].H && Z[i].M > Z[j].M || Z[i].M == Z[j].M && Z[i].S > Z[j].S)
            {
                temp = Z[i];
                Z[i] = Z[i+1];
                Z[i+1] = temp;
            }
        }
    }
    printf("\n");
    for(int i = 0;i < ZamerCount;i++)
        printf("%d:%d:%d %0.1lf\n",Z[i].H,Z[i].M,Z[i].S,Z[i].value);

    double sred = 0;
    for(int i = 0;i < ZamerCount;i++)
        sred = sred + Z[i].value;
    sred = sred / ZamerCount;
    printf("\nСреднее арифметическое:%lf\n\n",sred);

    //Создание массива структур
    struct zumer *Z1 = (struct zumer*)malloc(ZamerCount * sizeof(struct zumer));
    int counter = 0;
    for(int i = 0;i < ZamerCount;i++)
    {
        if(Z[i].value > sred)
        {
            Z1[counter] = Z[i];
            counter++;
        }
    }

    // Вывод этого дерьма
    for(int i = 0;i < counter;i++)
        printf("%d:%d:%d %0.1lf\n",Z1[i].H,Z1[i].M,Z1[i].S,Z1[i].value);

    FILE *file1 = fopen("output.txt","wt");
    fprintf(file1,"%d\n",counter);
    // Вывод этого дерьма в файл
    for(int i = 0;i < counter;i++)
        fprintf(file1,"%d:%d:%d %0.1lf\n",Z1[i].H,Z1[i].M,Z1[i].S,Z1[i].value);

    free(Z);
    free(Z1);
    fclose(file);
    fclose(file1);
    // Битовые поля что-то страшное, выборку можн ооформить а можно и не оформлять в функцию
    return 0;
}