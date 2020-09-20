/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: G - Мин-Макс-Среднее
Дата: 21.11.2019
*/
#include <iostream>

using namespace std;
void MinMaxSred(double *ar1,double *ar2,int n1)
{
    double Max,Min,Sred;
    Max = -10000000;
    Min = 10000000;
    Sred = 0;
    for(int i = 0;i < n1;i++)
    {
        if(*(ar1 + i) > Max)Max = *(ar1 + i);
        if(*(ar1 + i) < Min)Min = *(ar1 + i);
        Sred = Sred + *(ar1 + i);
    }
    Sred = Sred / n1;
    *ar2 = Min;
    *(ar2 + 1) = Max;
    *(ar2 + 2) = Sred;
}
//10.3lf
//-99999.999     98.309 -33297.157

//-99999.999     98.309 -33297.157
//-100000.000     98.309 -33297.156
int main()
{
    const int n = 1000;
    double a[n];
    int n1;
    scanf("%d",&n1);
    for(int i = 0;i < n1;i++)
        cin>>a[i];

    double a1[3];// Массив для max min sred
    MinMaxSred(a,a1,n1);
    printf("%10.6f%10.6f%10.6f",a1[0],a1[1],a1[2]);
    return 0;
}