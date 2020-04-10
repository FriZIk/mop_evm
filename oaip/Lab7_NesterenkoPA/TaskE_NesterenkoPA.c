/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: E. 2D массив со строками разной длины
Дата: 14.12.2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct mda
{
    int pointer;
    int a[100];
};


int main()
{
    const n = 1000;
    int n1;
    scanf("%d",&n1);
    int q;
    scanf("%d",&q);
    struct mda st[n];
    //struct mda * st = (struct mda*)malloc(n * sizeof(struct mda));
    for(int j = 0;j < q;j++)
    {
        int i,x;
        scanf("%d %d",&i,&x);
        st[i].a[st[i].pointer] = x;
        st[i].pointer++;
    }

    for(int i = 0;i < n1;i++)
    {
        int len = st[i].pointer;
        for(int j = 0;j < st[i].pointer;j++)
        {
            if(j != st[i].pointer - 1)printf("%d ",st[i].a[j]);
            else printf("%d ",st[i].a[j]);
        }
        if(i != n1 -1)printf("\n");
    }
    return 0;
}