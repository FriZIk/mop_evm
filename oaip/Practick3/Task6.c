#include <stdio.h>

int logic(int a,int b,char c)
{
    switch(c)
    {
        case '&':return a * b;break; // Конъюнкция
        case '|':return a + b;break; // Дизъюнкция
        case '~':                    // Инверсия
            if(a*b != 0)return 0;
            else return 1;
        break;
        case '=':return a & b;break; // Эквивалентность
    }
}

int main()
{
    int a,b;
    char c;
    while(1)
    {
        scanf("%d %c %d",&a,&c,&b);
        int result = logic(a,b,c);

        if(result != 0)printf("%d",1);
        else printf("%d",0);
    }
    return 0;
}