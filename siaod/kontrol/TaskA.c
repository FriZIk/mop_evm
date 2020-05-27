/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: A - Максимум в списке
Дата: 16.05.2020
*/

#include <stdio.h>
#include <stdlib.h>

struct List
{
    int Data;
    struct List* next;
    struct List* prev;
};
typedef struct List List;

void init(List **Head) // Инициализация пустого списка
{   
    
    (*Head) = (List*)malloc(sizeof(List));
    (*Head)->Data = NULL;
    (*Head)->next = (*Head); // указатель на следующий узел
    (*Head)->prev = (*Head); // указатель на предыдущий узел
}

int main()
{
    int n = 0;
    scanf("%d",&n);

    List *Head = (List*)malloc(sizeof(List));
    init(&Head);

    int var;
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&var);
        if(i != 0)
        {
            List *New = (List*)malloc(sizeof(List));
            List *Backup = (List*)malloc(sizeof(List));
            Backup = Head->prev;

            New->Data = var;
            New->next = Head;
            New->prev = Backup;

            Head->prev = New;
            Backup->next = New;
        }
        else Head->Data = var;
    }

/*
    for(int i = 0;i < n;i++)
    {
        printf("%d ",Head->Data);
        Head = Head->next;
    }*/

   // printf("\n");
    int max = -19999999,maxindex;
    for(int i = 0;i < n;i++)
    {
        if(Head->Data > max)
        {
            max = Head->Data;
            maxindex = i; 
        }
        Head = Head->next;
    }

    //printf("Максимальный индекс:%d\nМаксимальный элемент:%d\n",maxindex,max);

    //printf("%d ",Head->Data);

    // Замена первой переменной
    
    List* Temp = Head;
    for(int i = 0;i < maxindex;i++)
        Temp = Temp->next;
    //printf("%d \n",Temp->Data);
    Temp->prev->next = Temp->next;
    Temp->next->prev = Temp->prev;

    /*
    for(int i = 0;i < n-1;i++)
    {
        printf("%d ",Head->Data);
        Head = Head->next;
    }
    printf("\n");*/

    if(maxindex != 0)
    {
        List *New = (List*)malloc(sizeof(List));
        int temp = Head->Data;
        New->prev = Head;
        New->next = Head->next;
        New->Data = temp;

        Head->Data = max;
        Head->next = New;
        Head->next->prev = New;
    }

    for(int i = 0;i < n;i++)
    {
        printf("%d ",Head->Data);
        Head = Head->next;
    }

    return 0;
}