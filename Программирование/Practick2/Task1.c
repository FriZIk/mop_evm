#include <stdio.h>

int main()
{
    int a[3];
    int b[3];

    while(1)
    {
        scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
        scanf("%d.%d.%d",&b[0],&b[1],&b[2]);

        if(b[2] > a[2])printf("%d.%d.%d",a[0],a[1],a[2]);
        if(b[2] < a[2])printf("%d.%d.%d",b[0],b[1],b[2]);

        if(b[2] == a[2])
        {
            if(b[1] > a[1])printf("%d.%d.%d",a[0],a[1],a[2]);
            if(b[1] < a[1])printf("%d.%d.%d",b[0],b[1],b[2]);

            if(b[1] == a[1])
            {
                if(b[0] > a[0])printf("%d.%d.%d",a[0],a[1],a[2]);
                if(b[0] < a[0])printf("%d.%d.%d",b[0],b[1],b[2]);

                if(b[0] == a[0])printf("одно и тоже!!!");
            }
        }
        printf("\n-------------------------------------\n");
    }
    return 0;
}