/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: G. Треугольное число
Дата: 10.10.2019
*/

#include <iostream>

using namespace std;

int main(void)
{
    unsigned long long int n;
    cin>>n;
    unsigned long long int chislo = 0;
    for(unsigned long long int i = 0;i<n;i++)
    {
        chislo = chislo + (i+1);
    }
    //5000000000
    cout<<chislo;
    return 0;
}