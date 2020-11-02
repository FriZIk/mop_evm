#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

struct Pixel
{
    char Red[10];
    char Green[10];
    char Blue[10];
};

void PrintFunction(struct Pixel *Pixels,int NumCols,int NumRows)
{
    for(int i = 0;i < NumRows*NumCols;i++) printf("%s%s%s ",Pixels[i].Red,Pixels[i].Green,Pixels[i].Blue);
    /*for(int i = 0;i < NumRows;i++)
    {
        for(int j = 0;j < NumCols;j++)
            printf("%s%s%s ",Pixels[i+j].Red,Pixels[i+j].Green,Pixels[i+j].Blue);
        printf("\n");
    }*/
}

void GetCountFunc(FILE *InputFile,int *NumRows,int *NumCols)
{
    InputFile = fopen("input.txt","rt");
    fscanf(InputFile,"%d %d",&*NumRows,&*NumCols);
}

int InputFunction(FILE *InputFile,struct Pixel *Pixels,int *NumRows,int *NumCols)
{
    int NumberOfPixel = 0;
    for(int i = 0;i < *NumRows;i++)
    {
        for(int j = 0;j < *NumCols;j++)
        {
            char Buffer[100];
            fscanf(InputFile,"%s ", Buffer);
            int len = strlen(Buffer);

            int StartIndex = 0,FinishIndex;
            char b[10];
            int Counter = 0,Number = 1;
            for(int i  = 0;i <= len;i++)
            {
                if(i % 2 == 0 && i != 0)
                {  
                    int Len; // Промежуточная длина для числа
                    switch(Number)
                    {
                        case 1:
                            Len = strlen(b);
                            for(int i = 0;i < Len;i++)
                                Pixels[NumberOfPixel].Red[i] = b[i];
                            Number = 2;
                        break;
                        case 2:
                            Len = strlen(b);
                            for(int i = 0;i < Len;i++)
                                Pixels[NumberOfPixel].Green[i] = b[i];
                            Number = 3;
                        break;
                        case 3:
                            Len = strlen(b);
                            for(int i = 0;i < Len;i++)
                                Pixels[NumberOfPixel].Blue[i] = b[i];
                            NumberOfPixel++;
                            Number = 1;
                        break;
                    }
                    Counter = 0;
                }
                b[Counter] = Buffer[i];
                Counter++;
            }
        }
    }
    return NumberOfPixel;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    
    struct Pixel *Pixels;
    int NumRows = 0; // Кол-во строк
    int NumCols = 0; // Кол-во столбцов

    FILE *InputFile = fopen("input1.txt","rt");
    GetCountFunc(InputFile,&NumRows,&NumCols);
    
    Pixels = (struct Pixel*)calloc(NumCols * NumRows,  sizeof(struct Pixel));
    int NumberOfPixel = InputFunction(InputFile,Pixels,&NumRows,&NumCols);

    if(DEBUG == 1)
    {
        printf("Кол-во строк:%d\nКол-во столбцов:%d\n",NumRows,NumCols);
        PrintFunction(Pixels,NumCols,NumRows);
    }

    return 0;
}