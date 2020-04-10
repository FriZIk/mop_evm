#include <stdio.h>

void a()//Чёт-нечёт
{
    int a;
    scanf("%d",&a);
    if(a % 2 == 0)printf("even\n");
    else printf("odd\n");
}

void b()//Среднее число
{
    int n,m,k;
    int sred;

    scanf("%d %d %d",&n,&m,&k);
    if(n == m || m == k || k == n)
    {
        printf("Ошибка");
    }
    else
    {
        if(n>m)
        {
            if(n>k)
            {
                if(k>m)
                {
                    sred = k;
                }
                else sred = m;
            }
            else sred = n;
        }
        if(n<m)
        {
            if(n<k)
            {
                if(k<m)
                {
                    sred = k;
                }
                else sred = m;
            }
            else sred = n;
        }
    }

    printf("%d\n",sred);
}

void c()//Номер подъезда
{
    int NumberFlat;
    scanf("%d",&NumberFlat);
    //int PodezdNumber = 0;
    if(NumberFlat >= 1 && NumberFlat <= 36)printf("%d\n",1);
    if(NumberFlat >= 37 && NumberFlat <= 70)printf("%d\n",2);
    if(NumberFlat >= 71 && NumberFlat <= 106)printf("%d\n",3);
    else printf("Ошибка такой квартиры нет!\n");
}

void d()//Время года
{
    int Mounth;
    scanf("%d",&Mounth);
    if(Mounth == 1 || Mounth == 12 || Mounth == 2)printf("Winter\n");
    if(Mounth == 3 || Mounth == 4 || Mounth == 5)printf("Spring\n");
    if(Mounth == 6 || Mounth == 7 || Mounth == 8)printf("Summer\n");
    if(Mounth == 9 || Mounth == 10 || Mounth == 11)printf("Autumn\n");
}

void e()//Месяц года
{
    int Mounth;
    scanf("%d",&Mounth);
    switch(Mounth)
    {
        case 1:printf("January\n");break;
        case 2:printf("February\n");break;
        case 3:printf("March\n");break;
        case 4:printf("April\n");break;
        case 5:printf("May\n");break;
        case 6:printf("June\n");break;
        case 7:printf("July\n");break;
        case 8:printf("Auogst\n");break;
        case 9:printf("September\n");break;
        case 10:printf("October\n");break;
        case 11:printf("November\n");break;
        case 12:printf("December\n");break;
        default:printf("Неправильный месяц!!!\n");
    }
}

int main(void)
{
    int var;
    while(1)
    {   
        printf("Введите номер программы:");
        scanf("%d",&var);
        switch(var)
        {
            case 1:a();break;
            case 2:b();break;
            case 3:c();break;
            case 4:d();break;
            case 5:e();break;
            default:printf("Неизвестная программа");
        }
    }
    return 0;
}