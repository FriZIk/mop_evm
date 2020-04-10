/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: B. Клад
Дата: 08.02.2020
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    const int n = 260;
    char str[n];
    scanf("%s",str);
    int sumN = 0,sumS = 0,sumW = 0,sumE = 0;
    int len = strlen(str);
    int a,step = 1,sum = 0;

    char str1[100];int counter = 0,len1;

    for(int i = 0;i < len;i++)
    {
        switch(str[i])
        {
            default :
                str1[counter] = str[i];
                counter++;
                //a = (int)str[i] - 48;
                //sum = sum + a * step;
                //step = step * 10;
            break;
            case 'N':
                sumN = sumN + atoi(str1);
                len1 = strlen(str1);
                for(int i = 0;i < len;i++)
                    str1[i] = ' ';
                step = 1; 
                counter = 0;;
                sum = 0;
            break;
            case 'S':
                sumS = sumS + atoi(str1);
                len1 = strlen(str1);
                for(int i = 0;i < len;i++)
                    str1[i] = ' ';
                step = 1;
                counter = 0;
                sum = 0;
            break;
            case 'W':
                sumW = sumW + atoi(str1);
                len1 = strlen(str1);
                for(int i = 0;i < len;i++)
                    str1[i] =' ';
                step = 1;
                counter = 0;
                sum = 0;
            break;
            case 'E':
                sumE = sumE + atoi(str1);
                len = strlen(str1);
                for(int i = 0;i < len;i++)
                    str1[i] = ' ';
                step = 1;
                counter = 0;
                sum = 0;
            break;
        }
    }
    int Delta1,Delta2;
    Delta1 = sumE - sumW;
    Delta2 = sumN - sumS;

    if(Delta1 > Delta2)
    {
        if(Delta1 < 0)printf("%dW",Delta1 * -1);
        else printf("%dE",Delta1);
        if(Delta2 < 0)printf("%dS",Delta2 * -1);
        else printf("%dN",Delta2);  
    }
    else
    {
        if(Delta2 < 0)printf("%dS",Delta2 * -1);
        else printf("%dN",Delta2);  
        if(Delta1 < 0)printf("%dW",Delta1 * -1);
        else printf("%dE",Delta1); 
    }
    return 0;
}