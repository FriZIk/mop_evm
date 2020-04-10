/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: C. Коровы Анатолия
Дата: 25.01.2020
*/
 
#include <iostream>
 
using namespace std;
 
int main()
{
    
    int k,n,q;
    float m;
    cin>>k>>m>>n>>q;
    double result = k * m * n * q;
    
    if(result > int(result))result = result+1;
    cout<<(int)result;
    return 0;
}