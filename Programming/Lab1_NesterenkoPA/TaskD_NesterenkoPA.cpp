/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: D
Дата: 05.10.2019
*/

#include <iostream>

using namespace std;

int main(void)
{
    long long int a, b;
    cin>>a>>b;
    int c = ((a%2 == 0) && (b%2 == 0))||((a%2 !=0) && (b%2 !=0));
    unsigned long long int d = a * b * c;
    cout<<d;
    return 0;
}
