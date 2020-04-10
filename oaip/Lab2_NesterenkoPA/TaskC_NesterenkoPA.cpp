/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: C. Операция и операнд
Дата: 10.10.2019
*/

#include <iostream>

using namespace std;

int main(void)
{
    long long int x,n;
    //scanf("%d",&x);
    //scanf("%d",&n);
    cin>>x>>n;
    int a,cod;
    for(int i=0;i<n;i++)
    {
        //scanf("%d",&a);
        //scanf("%d",&cod);
        cin>>a>>cod;
        switch(cod)
        {
            case 1:x = x + a;break;
            case 2:x = x - a;break;
            case 3:x = x * a;break;
            case 4:x = x / a;break;
        }
    }
    cout<<x;
    return 0;
}
/*for(int i = 0;i<n;i++)
    {
        long long int stepen = 1;
        for(int j = 0;j<i;j++)
        {
            stepen = stepen * c;
        }
        sumC = sumC + stepen;
    }

    for(int i = 0;i<n;i++)
    {
        long long int stepen = 1;
        for(int j = 0;j<i;j++)
        {
            stepen = stepen * d;
        }
        sumD = sumD + stepen;
    }*/