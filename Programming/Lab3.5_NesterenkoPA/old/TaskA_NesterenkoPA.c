/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: A - Поиск в строке
Дата: 24.10.2019
*/

#include <stdio.h>

int main(void)
{
   const int n = 30000;
   char str[n];
   fgets(str,n + 2,stdin);
   char a;
   scanf("%c",&a);
   char *u;

   int counter = 0,counter1,triger = 0;
   for(u = str;*u;++u)
   {
      counter++;
      if(*u == a && triger == 0)
      {
         triger = 1;
         counter1 = counter;
      }
   }
   printf("%d",counter1);
   return 0;
}