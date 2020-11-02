/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: C. Пять знаков
Дата: 08.02.2020
*/

#include <stdio.h>

int main()
{
    unsigned long long int a  = 0;
    scanf("%lld",&a);

    unsigned int back = a;
    int raz = 0; // кол-во разрядов
    while( back != 0)
    {
        back = back / 10;
        raz++;
    }
    back = a;
    if(raz == 5)
    {
        int b,c,d,e,f;
        b = back / 10000;
        c = (back - b * 10000)/1000;
        d = (back - b * 10000 - c * 1000)/100;
        e = (back - b * 10000 - c * 1000 - d * 100)/10;
        f = back % 10;
        printf("%d%d%d%d%d",f,e,d,c,b);

    }
    if(raz < 5)
    {
        //100000
        if (a % 10000 == a)
        {
            int n = 0;
            if( a / 1000 != 0)printf("0%d",a);
            else
            {
                if(a / 1000 == 0 && a / 100 != 0)printf("00%d",a);
                else
                {
                    if(a / 1000 == 0 && a / 100 == 0 && a /10 != 0)printf("000%d",a);
                    else printf("0000%d",a);
                }
            }
        }
    }
    back = a;
    if(raz > 5)
    {
        int a1[18];
        for(int i = 0;i < 18;i++)
        {
            a1[i] = back % 10;
            back = back / 10;
        }
        for(int i = raz - 1;i >= 0;i--)printf("%d",a1[i]);
        printf("\n");
        for(int i = raz - 1;i >= raz - 5;i--)printf("%d",a1[i]);
    }  
    return 0;
}