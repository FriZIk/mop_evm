#include <stdio.h>
#include <math.h>

using namespace std;

void Func1()
{
    float y,x;
    printf("%s","Введите два числа:");
    scanf("%f%f",&x,&y);
    y = x * 25 - 16 * sqrt(x);
    printf("%f \n",y);
}

void Func2()
{
    int a,b,temp;
    printf("%s","Введите два числа:");
    scanf("%d%d",&a,&b);
    temp = a;
    a = b;
    b = temp;
    printf("%d %d \n",a,b);
}

void Func3()
{
    int a;//Четырёхзначное число
    printf("%s","Введите четырёхзначное число:");
    scanf("%d",&a);
    a = a % 1000;
    printf("%d \n",a);
}

void Func4()
{
    int a;//Четырёхзначное число
    int b;//Ещё одно число
    printf("%s","Введите четырёхзначное число:");
    scanf("%d",&a);
    b = (a%1000)*10 + a/1000;
    printf("%s%d %d\n","Исходное число и результат работы:",a,b);
}

void Func5()
{
    int x;
    printf("Введите число:");
    //if(abs(x) == 1)prinf("Да");
    //else printf("Нет");
    if(x > 8 || x < -8)prinf("Да");
    else printf("Нет");
}

void Func6()//Задача с конём
{
    int x1,y1,x2,y2;
    prinf("Введите координаты:");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    
}

int main(void)
{   
    int Choose;
    while(1)
    {
        printf("%s","Введите номер программы:");
        scanf("%d",&Choose);
        switch(Choose)
        {
            case 1:Func1();break;
            case 2:Func2();break;
            case 3:Func3();break;
            case 4:Func4();break;
            case 5:Func5();break;
            default:printf("%c","Error!!!");
        }
    }
    return 0;
}