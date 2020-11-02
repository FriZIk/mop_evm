/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: E. Советник Короля Инфа
Дата: 08.02.2020
*/

//#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    double pk,mk;
    double pe,me;

    cin>>pk>>mk>>pe>>me;
    //scanf("%d %d %d %d",&pk,&mk,&pe,&me);
    
    double inf = pk - 7 * pe;
    if(mk*0.2 <= me && inf > 0)printf("YES");
    else printf("NO");

    return 0;
}