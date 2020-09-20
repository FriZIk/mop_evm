#include <stdio.h>
#include <string.h>


// Не ришил тут что-то лютое я считываю а оно не считывается не понимаю что не так сейчас попробую переписать наверное
//22.00 - 23.03 не уврене что полностью правильно но вроде на собственном примере рабоатет исправно

int main()
{
    FILE *file = fopen("input.txt","rt");
    //Exmaple(file); Если бы можно было с двумерным массивом

    //Попробуем без него
    int n = 0;
    fscanf(file,"%d",&n);
    const int n1 = 1000;
    char str[n1];
    int Index = 0;
    for(int i = 0;i < n;i++)
    {
        //printf("(%d)",Index);
        char Buffer[n1];
        fscanf(file,"%s",Buffer);
        int len = strlen(Buffer);
        //printf("%d\n",len);
        for(int i = 0;i < len;i++)
        {
            str[Index] = Buffer[i];
            Index++;
        }
        str[Index] = '~';
        //printf("((%c))",str[Index]);
        Index++;
    }

    int len = strlen(str);
    char FinalString[n1];
    int StartIndexArray[n1];
    Index = 0;
    for(int i = len - 1;i > 0;i--)
    {
        if(str[i] == '~')
        {
            StartIndexArray[Index] = i;
            //printf("%d",Index);
            Index++;
        }
        //else printf("%c",str[i]);
    }

    /*printf("\n%d\n",Index);
    for(int i = 0;i < Index;i++)
        printf("%d ",StartIndexArray[i]);
    printf("\n");*/
    int B = Index;
    Index = 0;
    for(int j = 0;j < B;j++)
    {
        if(j == B - 1)
        {
            for(int i = StartIndexArray[j + 1];i < StartIndexArray[j];i++)
                printf("%c",str[i]);
        }
        else
        {
            for(int i = StartIndexArray[j + 1] + 1;i < StartIndexArray[j];i++)
                printf("%c",str[i]);   
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}