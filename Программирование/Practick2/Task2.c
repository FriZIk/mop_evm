#include <stdio.h>
#include <string.h>

int main()
{
    const int n = 3; // Размер массива
    int a[] = {123,42353,412};
    float b[] = {3213.23,-1.00,-123123142.22};
    char *c[] = {"kjfhsd kdewq","dewqdewqdew","wasdwad"};

    //for(int i=0;i<n;i++)printf("%s\n",c[i]);
    for(int i = 0;i <= 62;i++)printf("-"); 
    printf("\n");
    
    char *d[] = {"Id","Names","Values"};

    // Отрисовка верхних строк
    for(int i=0;i<3;i++)
    {
        printf("|"); 
        int StopTriger = 0;
        switch(i)
        {
            case 0:StopTriger = 4;break;
            //5 32 : 32-5=27 27/2 = 13/5  либо 13 либо 14 
            case 1:StopTriger = 12;break;
            case 2:StopTriger = 7;break;
        }

        for(int j = 0;j < StopTriger;j++)printf(" ");
        printf("%s",d[i]);
        for(int j = 0;j < StopTriger;j++)printf(" ");
    }
    printf("|\n");
    for(int i = 0;i <= 62;i++)printf("-");
    printf("\n");

    // Отрисовка содержания  таблицы
    for(int i = 0;i < n;i++)
    {
        // Размер для Id
        int Razmer1 = 1;
        printf("| ");
        printf("%d",a[i]);
        while(a[i] != 0)
        {
            a[i] = a[i]/10;
            Razmer1++;
        }
        for(int j = 0;j < 10-Razmer1;j++)printf(" ");
        
        printf("| ");
        int Razmer2 = 32;
        for(int i=0;i < Razmer2;i++)printf(" ");

        //Размер для Values
        printf("| ");
        int Razmer3 = 3; // 3 символа на запятую
        int temp = (int)b[i];
        while(a[i] != 0)
        {
            b[i] = b[i]/10;
            Razmer3++;
        }
        for(int j = 0;j < 10-Razmer1;j++)printf(" ");

    }

    for(int i = 0;i <= 62;i++)printf("-");
    printf("\n");
    return 0;
}