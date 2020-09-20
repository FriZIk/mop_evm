/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: D. Разность сумм рядов
Дата: 10.10.2019
*/

#include <iostream>

using namespace std;

int main(void)
{
    long long int n,c,d;
    long long int sumC=0,sumD=0;
    
    cin>>n>>c>>d;

    long long int stepen = 1;
    for(int j = 0;j<n;j++)
    {
        stepen = stepen * c;
        sumC = sumC + stepen;
    }

    stepen = 1;
    for(int j = 0;j<n;j++)
    {
        stepen = stepen * d;
        sumD = sumD + stepen;
    }
    
    cout<<sumD-sumC;
    return 0;
}