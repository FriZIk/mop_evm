/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: A - Сумма двух
Дата: 21.11.2019
*/

#include <iostream>

using namespace std;

long long int sum(long long int a,long long int b)
{
    return a + b;
}

int main()
{
    long long int a,b;
    cin>>a>>b;
    cout<<sum(a,b);
    return 0;
}