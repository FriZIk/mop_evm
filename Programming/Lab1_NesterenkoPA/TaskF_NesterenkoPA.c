/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: F
Дата: 05.10.2019
*/

#include <stdio.h>

int main(void)
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int a1,b1,c1;
    scanf("%d %d %d",&a1,&b1,&c1);
    int sec = 0;

    int count1 = (a > a1)*(a - a1);
    int count2 = (a < a1)*(a1 - a);
    int countrezult = count1+count2;
    sec = sec + countrezult*3600;

    count1 = (b > b1)*(b - b1);
    count2 = (b < b1)*(b1 - b);
    countrezult = count1+count2;
    sec = sec + countrezult*60;

    count1 = (c > c1)*(c - c1);
    count2 = (c < c1)*(c1 - c);
    countrezult = count1+count2;
    sec = sec + countrezult;

    // count1 = (T1 > T2) * (T1 - T2);
    // count2 = (T2 < T1) * (T2 - T1);  

    count1 = (sec > 24*3600 - sec) * ( 24*3600 - sec);
    count2 = (sec < 24*3600 - sec) * ( sec);
    sec = count1+count2;
    

    printf("%d \n",sec);

    return 0;
}