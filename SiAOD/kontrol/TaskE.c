#include <stdio.h>

#define N 1000000

struct List
{
    int Data;
    struct List* next;
    struct List* prev;
};
typedef struct List List;

void Init(List **Head) // Инициализация пустого списка
{   
    
    (*Head) = (List*)malloc(sizeof(List));
    (*Head)->Data = NULL;
    (*Head)->next = (*Head); // указатель на следующий узел
    (*Head)->prev = (*Head); // указатель на предыдущий узел
}

void AddElementHead(List *Head,int var,int Count)   //Добавление узгла в голову списка
{   
    if(Count != 0)
    {
        List *New = (List*)malloc(sizeof(List));
        List *Backup = (List*)malloc(sizeof(List));
        Backup = Head->next;
        Head->next = New;

        New->Data = Head->Data;
        New->prev = Head;
        New->next = Backup;

        Backup->prev = New;
        Head->Data = var;
    }
    else Head->Data = var;
}

int main()
{
    int n;
    scanf("%lld",&n);
    int a = 1; 
    int counter = 0; // Количество операций
    List *Head = (List*)malloc(sizeof(List)); 
    Init(&Head);
    int index = 0;
    AddElementHead(Head,a,index);
    index++;


    while(a * 3 <= n)
    {
        a = a * 3;
        counter++;
        AddElementHead(Head,a,index);
        index++;
    }

    while(a * 2 <= n)
    {
        a = a * 2;
        counter++;
        AddElementHead(Head,a,index);
        index++;
    }

    while(a + 1 <= n)
    {
        a = a + 1;
        counter++;
        AddElementHead(Head,a,index);
        index++;
    }

    counter = counter + (n - a);

    printf("%lld\n",counter);
    for(int i = 0;i < index;i++)
    {
        if(i == index - 1)
        {
            Head = Head->prev;
            printf("%d",Head->Data);
        }
        else
        {
            Head = Head->prev; 
            printf("%d ",Head->Data); 
        }
    }


    return 0;
}
