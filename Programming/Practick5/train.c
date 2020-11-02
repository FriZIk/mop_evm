#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StudentType
{
    char Name[30];
    char Group[5];
    double Ball;
};

void WriteLogArray(FILE *pointer,int n1,struct StudentType *Stud) // Функция выводит массив структур
{
    for(int i = 0;i < n1;i++)
    {
        int len1,len2;
        len1 = strlen(Stud[i].Name)/2;
        len2 = strlen(Stud[i].Group)/2;
        fprintf(pointer,"%-30s %-5s %10.2lf\n",Stud[i].Name,Stud[i].Group,Stud[i].Ball);
    }
    printf("\n");
}

int main()
{
    FILE *InputFile = fopen("input.txt","rt");
    if(InputFile != 0)
    {
        fprintf(stdout,"Файл успешно открылся!!!\n");

        int n1 = 0;
        fscanf(InputFile,"%d",&n1);
        printf("Кол-во строк:%d\n\n",n1);
        struct StudentType *StudentArray = (struct StudentType*)malloc(n1 * sizeof(struct StudentType));
        
        for(int i = 0;i < n1;i++)
        {
            fscanf(InputFile,"%s %s %lf",&StudentArray[i].Name,
            &StudentArray[i].Group,
            &StudentArray[i].Ball);
        }
        WriteLogArray(stdout,n1,StudentArray); // Вывод массива на консоль для отладки
        
        printf("Сортировка массива по возрастанию поля Name!!!\n");
        for(int i = 0;i < n1 - 1;i++) // Тупая сортировка пузырьком 
        {
            for(int j = i + 1;j < n1;j++)
            {
                if(strlen(StudentArray[i].Name) > strlen(StudentArray[j].Name))
                {
                    struct StudentType TempStruct = StudentArray[i];
                    StudentArray[i] = StudentArray[j];
                    StudentArray[j] = TempStruct;
                }
            }
        }
        WriteLogArray(stdout,n1,StudentArray); // Вывод массива на консоль для отладки
        fclose(InputFile);

        FILE *OutputFile = fopen("info.dat","wb");// Вывод в бинарный файл
        if(OutputFile != 0)
        {
            fprintf(OutputFile,"%d\n",n1);
            
            for(int i = 0;i < n1;i++)
            {
                fprintf(OutputFile,"%s %s %lf\n",StudentArray[i].Name,
                StudentArray[i].Group,
                StudentArray[i].Ball);
            }

            fclose(OutputFile);

            FILE *InputFile = fopen("info.dat","rb");
            int n2;
            fscanf(InputFile,"%d",&n2);
            for(i t i = 0;i < n2;i++)
            {
                fscanf(InputFile,"%s %s %lf\n",StudentArray[i].Name,
                StudentArray[i].Group,
                StudentArray[i].Ball);
            }
            for(int i = 0;i <)
            free(StudentArray);
        }
    }
    else printf("We have a problem\n");
    return 0;
}
/*
void NotGoodSort(int CountOfStudents, struct StudentsParametrs *Student) // Не работает
{
    for(int i = 0;i < CountOfStudents - 1;i++)
    {
        for(int j = i + j;j < CountOfStudents;j++)
        {
            if(strlen(Student[i].Surname) > strlen(Student[j].Surname))
            {
                struct StudentsParametrs Temp = Student[i];
                Student[i] = Student[j];
                Student[j] = Temp;
            }
            if(strlen(Student[i].Surname) == strlen(Student[j].Surname))
            {
                if(strlen(Student[i].Name) > strlen(Student[j].Name))
                {
                    struct StudentsParametrs Temp = Student[i];
                    Student[i] = Student[j];
                    Student[j] = Temp;
                }
                if(strlen(Student[i].Name) == strlen(Student[j].Name))
                {
                    if(Student[i].Group > Student[j].Group)
                    {
                        struct StudentsParametrs Temp = Student[i];
                        Student[i] = Student[j];
                        Student[j] = Temp;
                    }
                    if(Student[i].Group == Student[j].Group)
                    {
                        if(Student[i].Balls > Student[j].Balls)
                        {
                            struct StudentsParametrs Temp = Student[i];
                            Student[i] = Student[j];
                            Student[j] = Temp;
                        }
                    }
                }
            }     
        }
    }
}

*/