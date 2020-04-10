/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: E. Число Фибоначчи
Дата: 10.10.2019
*/

#include <iostream>

using namespace std;

int main()
{
    long long int a;//число фибоначи
    cin>>a;

    long long int realk1=0;//Рабочие числа фибоначи
    long long int realk2=1;

    for(int i=0;realk2<a;i++)
    {
        long long int temp = realk2;
        realk2 = realk1 + realk2;
        realk1 = temp;
    }
    if(realk2 > a)cout<<realk1;
    else cout<<realk2;
    return 0;
}