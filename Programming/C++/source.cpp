#include <iostream>
#include <math.h>

using namespace std;

struct Students
{
    char Surname[31];
    int Inf = 0,Rus = 0,Mat = 0;
    int DD1,MM1,HH1,mm1;
    int DD2,MM2,HH2,mm2;
    int SumBalls; 
    long long int Time1;
    long long int Time2;
};

void swap(struct Students *s1,struct Students *s2)
{
    struct Students temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main()
{
    int n; // Кол-во абитуриентов
    FILE *file = fopen("input.txt","rt");
    fscanf(file,"%d",&n);
    struct Students *Student = new struct Students[n];
    for(int i = 0;i < n;i++)
    {
        fscanf(file,"%s %d %d %d %d %d %d %d %d %d %d %d",
        &Student[i].Surname,&Student[i].Inf,&Student[i].Mat,
        &Student[i].Rus,&Student[i].DD1,&Student[i].MM1,&Student[i].HH1,
        &Student[i].mm1,&Student[i].DD2,&Student[i].MM2,&Student[i].HH2,
        &Student[i].mm2);
    }

    int count50 = 0;
    for(int i = 0;i < n;i++)
    {
        if(Student[i].Inf >= 50 && Student[i].Mat >= 50 && Student[i].Rus >= 50)
            count50++;
    }
    cout<<count50<<endl;
    
    // Начинаем сортировать
    for(int i = 0;i < n;i++) // Инициализация дополнительных полей структуры
    { 
        Student[i].SumBalls = Student[i].Inf + Student[i].Mat + Student[i].Rus;
        Student[i].Time1 = Student[i].mm1 + Student[i].HH1 * 60 + Student[i].DD1 * 24 * 60 + Student[i].MM1 * 31 * 24 * 60;
        Student[i].Time2 = Student[i].mm2 + Student[i].HH2 * 60 + Student[i].DD2 * 24 * 60 + Student[i].MM2 * 31 * 24 * 60;
    }

    for(int i = 0;i < n - 1;i++)
    {
        for(int j = i+1;j < n;j++)
        {
            if(Student[i].SumBalls < Student[j].SumBalls)
                swap(&Student[i],&Student[j]);

            if(Student[i].SumBalls == Student[j].SumBalls && Student[i].Inf < Student[j].Inf)
                swap(&Student[i],&Student[j]);
    
            if(Student[i].SumBalls == Student[j].SumBalls && Student[i].Inf == Student[j].Inf && Student[i].Mat < Student[j].Mat)
                swap(&Student[i],&Student[j]);

            if(Student[i].SumBalls == Student[j].SumBalls && Student[i].Inf == Student[j].Inf && Student[i].Mat == Student[j].Mat && Student[i].Rus < Student[j].Rus)
                swap(&Student[i],&Student[j]);

            if(Student[i].SumBalls == Student[j].SumBalls && Student[i].Inf == Student[j].Inf && Student[i].Mat == Student[j].Mat && Student[i].Rus == Student[j].Rus && Student[i].Time1 < Student[j].Time1)
                swap(&Student[i],&Student[j]);

            if(Student[i].SumBalls == Student[j].SumBalls && Student[i].Inf == Student[j].Inf && Student[i].Mat == Student[j].Mat && Student[i].Rus == Student[j].Rus && Student[i].Time1 == Student[j].Time1 && Student[i].Time2 < Student[j].Time2)   
                swap(&Student[i],&Student[j]); 
        }
    }

    for(int i = 0;i < n;i++)
    {
        if(Student[i].Inf >= 50 && Student[i].Mat >= 50 && Student[i].Rus >= 50)
        {
            if(i != count50 - 1)
            {
                printf("%d %s %d %d %d %d\n",
                i+1,Student[i].Surname,Student[i].SumBalls,Student[i].Inf,Student[i].Mat,
                Student[i].Rus);
            }
            else
            {
                printf("%d %s %d %d %d %d",
                i+1,Student[i].Surname,Student[i].SumBalls,Student[i].Inf,Student[i].Mat,
                Student[i].Rus);
            }
            
        }
    }

    fclose(file);
    delete[]Student;
    return 0;
}