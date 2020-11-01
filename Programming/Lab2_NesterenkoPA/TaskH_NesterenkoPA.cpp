/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: H. Простые множители
Дата: 10.10.2019
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int BackUpTrigerProst;
    int trigerProst = 0;
    
    for(int i = 0;i<=n;i++)
    {
        //Определение простоты числа
        trigerProst = 0;
        for(int j = 1;j<=n;j++)
        {
            if (i % j == 0)trigerProst++;
        }
        if(trigerProst == 2) 
        {
            if(BackUpTrigerProst != trigerProst)
                cout<<trigerProst<<endl;

            n = n / trigerProst;
            BackUpTrigerProst = trigerProst;
        }
    }
    cout<<n;
    return 0;
}