#include <stdio.h>

int main(void)
{
    const int n = 1000000;
    char str1[n];
    char str2[n];
    fgets(str1,n,stdin);
    fgets(str2,n,stdin);
    char *p1 = str1,*p2 = str2;
    int len1 = -1,len2 = -1;
    for(p1;*p1;p1++,len1++);
    for(p2;*p2;p2++,len2++);

    // Создаем массив уникальных 
    char str3[n],str4[n];
    int len3 = 1,len4 = 0;
    
    for(int i = 0;i< len1;i++)str3[i] == ' ';
    for(int i = 0;i < len2;i++)str4[i] == ' ';

    //Генерация первого массива уникальных эллементов 
    int triger = 1;  
    str3[0] = str1[0]; 
    for(int i = 0;i < len1;i++)
    {
        int triger = 0;
        for(int j = 1;j <= len3;j++)
        {
           if(str1[i] == str2[j])triger = 0;
        }
        printf("%d",triger);
    }
    printf("%d\n",len3);
    for(int i = 0;i < len3;i++)printf("%c",str3[i]);
    return 0;
}