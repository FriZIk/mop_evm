/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: B. Банкнота раздора
Дата: 25.01.2020
*/

#include <stdio.h>

int main()
{
    long long int n = 0;
    scanf("%ld",&n);
    long long int last = n%10;
    long long int first = n/100000;
    long long int last_minus_one = (n%100) / 10;

    if(last == first && n%3 == 0 && last == last_minus_one && n%2 == 0)printf("YES");
    else printf("NO");
    return 0;
}

//123456