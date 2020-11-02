/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: E
Дата: 05.10.2019
*/

#include <stdio.h>

int main(void)
{
    // Не решил дегенрат блять
    unsigned short int a;
    scanf("%d",&a);
    unsigned short int n1,n2,l;//n1 - стартовый бит первый, n2 - стартовый бит второй, l - длина промежутков 
    scanf("%d %d %d",&n1,&n2,&l);

    unsigned short int b = a << (16-n2-l);
    b = b >> (16-l);
    b = b << n1;
    printf("B = %d\n",b);
    unsigned short int c = a << (16-n1-l);
    c = c >> (16-l);
    c = c << n2;
    printf("C = %d\n",c);

    unsigned short int m1,m2;
    unsigned short int m = 0xFFFF;
    
    m1 = m << (16-n2-l);
    m1 = m1 >> (16-l);
    m1 = m1 << n2;
    printf("M1 = %d\n",m1);

    m2 = m << (16-n1-l);
    m2 = m2 >> (16-l);
    m1 = m2 << n1;
    printf("M2 = %d\n",m2);

    unsigned short int otvet = b|c|((~(m1|m2))&a);
    printf("%d\n",otvet);

    return 0;
}