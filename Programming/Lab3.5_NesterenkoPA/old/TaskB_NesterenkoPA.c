/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: B. Деление строки на слова
Дата: 24.10.2019
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
   const int n = 100000;
   char str[n];
   fgets(str,n + 2,stdin);
   
   //Длина
   char *u;int len = 0;
   for(u = str;*u;++u,++len);

   //Подсчёт кол-ва
   int count = 0;
   int totalcount = 0;
   int countnozeos = 0;

   triger1 = 0,triger2 = 0;
   for(int i = 0;i < len;i++)
   {
      if(str[i] == ' ')
      {
         totalcount++;         
         if(str[i - 1] != ' ')count++;
         for(int j = i;str[i]!=' ';j++)
         {
            triger1++;
         }
         for(int j = i;j<len;j++)triger2++;
      }
      if(triger1 != triger2)count++;
   }
   
   countnozeos = len - totalcount;

   if(totalcount != len -1)
   {
      if(count == 0)
      {
         printf("%d\n",1);
         for(int  i =0;i < len;i++)printf("%c",str[i]);
      }
      else
      {
         printf("%d",count);
         if(str[0] != ' ')printf("\n");
         for(int  i =0;i < len;i++)
         {
            if(str[i] != ' ')
            {  
               countnozeos--;
               printf("%c",str[i]);
            }
            if(str[i] == ' ')
            {
               if(str[i -1] != ' ')
               {
                  if(countnozeos-1 != 0)printf("\n");   
               }
            }
         }
      }
   }
   else 
   {
      printf("%d\n",0);
   }
   return 0;
}
