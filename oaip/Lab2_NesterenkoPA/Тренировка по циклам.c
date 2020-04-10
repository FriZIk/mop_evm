#include <stdio.h>

void A()//Банковский процент
{
    int x;//Сумма превоначальная
    float p;//Кол-во процентов по вкладу
    int n;//Кол-во месяцев

    scanf("%d %F %d",&x,&p,&n);
    p = p/100;
    
    for(int i=0;i<n;i++)
    {
        float Count = x*p;
        if(Count + 0.5 >= (int)Count+1)x = x + (int)(Count+1);
        else x = x + (int)Count;
    }
    printf("%d\n",x);
}

void B()//Число Фибоначи
{
    int k;//число фибоначи
    scanf("%d",&k);

    int realk1=1;//Рабочие числа фибоначи
    int realk2=1;

    for(int i=1;i<=k-2;i++)
    {
        int temp = realk2;
        realk2 = realk1 + realk2;
        realk1 = temp;
    }

    printf("%d\n",realk2);
}

void C()//Сумма чисел в диапозоне(кажется пример неправильный)
{
    int a,b;
    scanf("%d %d",&a,&b);
    int resultSum = 0;
    for(int i = a;i<=b;i++)
        resultSum = i + resultSum;
    printf("%d\n",resultSum);
}

void D()//Произведение всех чисел в диапозоне(пример в прошлом и тут один и тот же)
{
    int a,b;
    scanf("%d %d",&a,&b);
    int resultPro = 1;
    for(int i = a;i<=b;i++)
        resultPro = i * resultPro;
    printf("%d\n",resultPro);
}

void E()//Сумма факториалов
{
    int n;
    scanf("%d",&n);
    int sum = 0;
    for(int i = 1;i<=n;i++)
    {
        int Facktorial = 1;
        for(int j = 1;j<=i;j++)//нахождение факториала числа
            Facktorial = Facktorial*j;
        sum = sum + Facktorial;
    }
    printf("%d\n",sum);
}

//Совем страх какой-то с рядами ну его void F()

void G()//Cумма кратных чисел
{
    int s,r,n;
    scanf("%d %d %d",&s,&r,&n);
    int sum = 0;
    for(int i = s;i<=r;i++)
    {
        if(i % n == 0)sum = sum + i;
    }
    printf("%d",sum);
}

void H()//m - степень
{
    int x,k;
    scanf("%d %d",&x,&k);
    int a=1;
    int FinishIndex;
    for(int i=0;a<x;i++)
    {
        a = a * k;
        FinishIndex = i;
    }
    if(a != x)printf("%d\n",-1);
    else printf("%d\n",FinishIndex+1);
}

//духота какая-то потом порешаю может быть int i()

int j()
{
    int x,n;
    scanf("%d %d",x,n);

    int a,b;

    while(x != 0)
    {
        b = x%n;
        x = x/n;
    }
}

void k()//Алгоритм Евклида
{
    int x,y;
    scanf("%d %d",&x,&y);
    while(y != 0)
    {
        int temp = y;
        y = x % y;
        x = temp;
    }
    printf("%d\n",x);
}

void l()//Сумма чётных цифр числа(чётных позиций) пример не правильный
{
    int x;
    scanf("%d",&x);
    int sum = 0;
    int chetTriger = 0;
    while(x != 0)
    {
        if(chetTriger % 2 == 0)
            sum = sum + x%10;
        x = x / 10;
        chetTriger++;
    }
    printf("%d\n",sum);
}

/*void o()//Все простые числа хз надо проверять делятся ли все предыдущие но я 
често говоря хз как это делать без массивов вообщем могила а не задача наверное 
я уже просто устал так как время 23.03
{
    int x,y;
    scanf("%d %d",&x,&y);
    for(int i = x;i <= y;i++)
    {
        if(i %)
    }
}*/

int main()
{
    while(1)
    {
        int x;
        scanf("%d",&x);
        switch(x)
        {
            case 1:A();break;
            case 2:B();break;
            case 3:C();break;
            case 4:D();break;
            case 5:E();break;
            case 6:printf("Тебе оно не надо ,ты молодой ,тебе всё легко...\n");
            case 7:G();break;
            case 8:H();break;
            case 9:printf("Тебе оно не надо ,ты молодой ,тебе всё легко...\n");
            case 10:j();break;
            case 11:k();break;
            case 12:l();break;
            default:printf("Нет такой программы!!!\n");
        }
    }
    return 0;
}