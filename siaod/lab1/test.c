#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Вриант номер 8

struct List
{
    int Data;
    struct List *next; 
    struct List *prev;
};
typedef struct List List;

void InitList(List **Head) // Инициализация пустого списка
{   
    (*Head) = (List*)malloc(sizeof(List));
    (*Head)->Data = NULL;
    (*Head)->next = (*Head); // указатель на следующий узел
    (*Head)->prev = (*Head); // указатель на предыдущий узел
}

void AddElementTail(List *Head,int var,int Count)// Добавление узла в хвост списка
{
    if(Count != 0)
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

void PrintList(List *Head,int Count) // Выдача текущего списка на экран
{
    List *Temp = (List*)malloc(sizeof(List));
    Temp = Head->next;
    printf("%d ",Head->Data);
    if(Count > 1)
    {
        do 
        {
            printf("%d ", Temp->Data);
            Temp = Temp->next; 
        }
        while (Temp != Head); // Пока не вернулись туда, откуда начали
    } 
    printf("\n");
}

void DeleteElementTail(List *Head,int Count) // Удаление узла из хвоста
{
    if(Count == 0) free(Head);
    else
    {
        List *Temp = (List*)malloc(sizeof(List));
        Temp = Head->prev;
        Temp->prev->next = Head;
        Head->prev = Temp->prev;
        free(Temp);   
    }
}

void DeleteElementHead(List *Head,int Count) // Удаление узла из головы
{
    if(Count == 0)free(Head);
    else
    {
        List *Temp = (List*)malloc(sizeof(List));
        Temp = Head->next;
        Head->Data = Temp->Data;
        Temp->next->prev = Head;
        Head->next = Temp->next;
        free(Temp);
    }
}

void DeleteList(List *Head) // Уничтожение списка с освобождением памяти
{
    while(Head->prev != Head) // Пока не вернулись туда, октуда начали
    {
        List *Temp = (List*)malloc(sizeof(List));
        Temp = Head->prev;
        Head->prev = Temp->prev;
        free(Temp);
    }
}

void AddElementConst(List *Head,int var,int Count) // Добавить новый узел перед узлом с заданным значением данных
{
    int triger = 0;
    List *Temp = (List*)malloc(sizeof(List));
    Temp = Head;
    while(Temp->Data != var && triger < Count)
    {
        Temp = Temp->next;
        triger++;
    }
    if(triger == Count) 
    {
        printf("Узла с таким значением не существует!\n");
        return;
    }
    else
    {
        printf("Введите новое значение:");
        scanf("%d",&var);
        List *New = (List*)malloc(sizeof(List));
    
        Temp->prev->next = New;
        New->prev = Temp->prev;
        New->next = Temp;
        Temp->prev = New;
        New->Data = var;
    }
}

void DeleteElementNumber(List *Head,int Index,int Count) // Удалить узел с указанным порядковым номером
{
    if(Count == 1)free(Head);
    else
    {
        List *Temp = (List*)malloc(sizeof(List));
        Temp = Head;
    
        for(int i = 1;i < Index;i++)
            Temp = Temp->next;

        Temp->prev->next = Temp->next;
        Temp->next->prev = Temp->prev;
        free(Temp);
    }
}

int main()
{
    setlocale(LC_ALL,"Russian");
    typedef struct List List;
    int Command = -1;
    List *Head = (List*)malloc(sizeof(List)); //Указатель на последний активный элемент или просто голова списка
    int var,Count = 0; 

    printf("Доступные команды:\n1) Инициализация пустого списка\n2) Уничтожение списка с освобождением памяти\n3) Добавление узла в голову списка\n4) Добавление узла в хвост списка\n5) Удаление узла из головы списка\n6) Удаление узла из хвоста списка\n7) Выдача текущего списка на экран\n8) Добавить новый узел перед узлом с заданным значением данных\n9) Удалить узел с указанным порядковым номером\n0) Завершение работы программы\n");
    while(Command != 0)
    {
        printf(">>>");
        scanf("%d",&Command);

        switch(Command)
        {
            case 0:break;                                             // Закончить выполнение программый
            case 1:                                                   // Инициализация пустого списка
               InitList(&Head);
               printf("Список инициализирован!\n");
            break;
            case 2:                                                   // Уничтожение списка с освобождением памяти
               DeleteList(Head);
               printf("Список удалён!\n");
               Count = 0;
               free(Head);
            break;
            case 3:                                                   // Добавление узла в голову списка
                printf("Введите новое значение:");
                scanf("%d",&var);
                AddElementHead(Head,var,Count);
                Count++;
            break;       
            case 4:                                                   // Добавление узла в хвост списка  
                printf("Введите новое значение:");
                scanf("%d",&var);
                AddElementTail(Head,var,Count);
                Count++;
            break;   
            case 5:                                                   // Удаление узла из хвоста списка 
                DeleteElementTail(Head,Count);
                if(Count != 0)Count--;
                if(Count == 0)InitList(&Head);
            break;   
            case 6:                                                   // Удаление узла из головы списка 
                DeleteElementHead(Head,Count);
                if(Count != 0)Count--;
                if(Count == 0)InitList(&Head);
            break;          
            case 7:                                                   // Выдача текущего списка на экран
                if(Head->next != Head || Count > 0)
                {
                    printf("Текущее содержимоее списка:");
                    PrintList(Head,Count);
                }
                else printf("Список пуст!\n");
            break;
            case 8:                                                   // Добавить новый узел перед узлом с заданным значением данных
                printf("Введите значение для поиска:");
                scanf("%d",&var);
                AddElementConst(Head,var,Count);
            break;
            case 9:                                                   // Удалить узел с указанным порядковым номером
                printf("Введите номер элемента для удаления:");
                scanf("%d",&var);
                if(Count != 0)
                    DeleteElementNumber(Head,var,Count);
            break;                                           
            default : printf("Неизвестная команда!\n");break;
        }
    }
    return 0;
}