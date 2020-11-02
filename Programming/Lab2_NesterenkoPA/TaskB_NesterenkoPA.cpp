/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: B. Казино-1
Дата: 10.10.2019
*/

#include <iostream>

using namespace std;

int main(void)
{
    long long int a;
    
    cin>>a;
    int proizvedB = 1;
    int proizvedC = 1;

    int b = a % 10000;
    int c = a / 10000;

    if(b > 10000) b = b / 10;
    if(c > 10000) c = c / 10;

    for(int i =0;i<4;i++)
    {
        proizvedB = proizvedB * b %10;
        b = b / 10;
    }

    for(int i = 0;i<4;i++)
    {
        proizvedC = proizvedC* c % 10;
        c = c / 10;
    }
    if(proizvedC == proizvedB && proizvedB %2 != 0) printf("YES");
    else printf("NO");
    return 0;
}