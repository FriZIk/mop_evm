/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: F. Квадрат ли?
Дата: 10.10.2019
*/

#include <iostream>

using namespace std;

int main()
{
    long long int n;
    int triger = 0;
    cin >> n;
    for(int i = 0;(i*i) <= n;i++)
    {
        if (i * i != n)triger = 0; 
        else triger = 1;
    }
    if(triger == 1)cout<<"YES";
    else cout << "NO";
    return 0;
}