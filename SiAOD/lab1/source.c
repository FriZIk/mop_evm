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
    (*Head)->Data = -1;
    (*Head)->next = (*Head); // указатель на следующий узел
    (*Head)->prev = (*Head); // указатель на предыдущий узел
}

int AddElementTail(List **Head,int var,int Count) // Добавление узла в хвост списка
{
    printf("%d\n",(*Head)->Data);
    if(Count != 0)
    {
        List *New = (List*)malloc(sizeof(List));
        List *Backup = (List*)malloc(sizeof(List));
        Backup = (*Head)->next; // сохранение указателя на следующий узел
        (*Head)->next = New; // предыдущий узел указывает на создаваемый
    
        New->Data = var;    // сохранение поля данных добавляемого узла
        New->next = Backup;
        New->prev = (*Head);

        Backup->prev = New;
    }
    else
    { 
        (*Head)->Data = var;
    }
    return Count + 1;
}

int AddELementHead(List **Head,int var,int Count)   //Добавление узгла в голову списка
{
    printf("%d\n",(*Head)->Data);
    if(Count != 0)
    {
        List *New = (List*)malloc(sizeof(List));
        List *Backup = (List*)malloc(sizeof(List));
        Backup = (*Head)->prev; // сохранение указателя на следующий узел
        (*Head)->prev = New; // предыдущий узел указывает на создаваемый
    
        New->Data = (*Head)->Data;    // сохранение поля данных добавляемого узла
        New->prev = Backup;
        New->next = (*Head);

        Backup->next = New;
    }
    (*Head)->Data = var;
    return Count + 1;
}

void PrintList(List *Head,int count) // Выдача текущего списка на экран
{
    List *Temp = (List*)malloc(sizeof(List));
    Temp = Head;
    if(count > 1)
    {    
        do 
        {
            printf("%d ", Temp->Data);
            Temp = Temp->prev; 
        }
        while (Temp != Head); // Пока не вернулись туда откуда начали 
    }else printf("%d",Head->Data);
    printf("\n");
}

void DeleteElementTail(List *Head,int Count) // Удаление узла из хвоста
{   
    if(Count == 0) free(Head);
    else
    {
        List *Temp = (List*)malloc(sizeof(List));
        Temp = Head->next;
        Temp->next->prev = Head;
        Head->next = Temp->next;
        free(Temp);   
    }
}

void DeleteElementHead(List *Head,int Count) // Удаление узла из головы
{
    if(Count == 0)free(Head);
    else
    {
        List *Temp = (List*)malloc(sizeof(List));
        Temp = Head->prev;
        Head->Data = Temp->Data;  
        Head->prev = Temp->prev;
        free(Temp);
    }
}

void DeleteList(List *Head,int Count) // Уничтожение списка с освобождением памяти
{
    printf("%d\n",Head->next->Data);
    for(int i = 0;i < Count - 1;i++)
    {
            List *Temp = (List*)malloc(sizeof(List));

            PrintList(Head,Count);
    }
    free(Head);
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
                Count = 0;
                InitList(&Head);
            break;
            case 2:                                                   // Уничтожение списка с освобождением памяти
                DeleteList(Head,Count);
                //printf("%d\n",Count);
                Count = 0;
            break;
            case 3:                                                   // Добавление узла в голову списка
                printf("Введите новое значение:");
                scanf("%d",&var);                                               
                Count = AddELementHead(&Head,var,Count);          
            break;       
            case 4:                                                   // Добавление узла в хвост списка  
                printf("Введите новое значение:");
                scanf("%d",&var);
                Count = AddElementTail(&Head,var,Count);
            break;   
            case 5:                                                   // Удаление узла из головы списка
                DeleteElementHead(Head,Count);
                if(Count != 0)Count--;
                if(Count == 0)InitList(&Head);
            break;   
            case 6:                                                   // Удаление узла из хвоста списка 
                DeleteElementTail(Head,Count);
                if(Count != 0)Count--;
                if(Count == 0)InitList(&Head);
            break;          
            case 7:                                                   // Выдача текущего списка на экран
                if(Count == 0)printf("Список пуст!\n");
                else PrintList(Head,Count);
            break;

            
            case 8:break;                                             // Добавить новый узел перед узлом с заданным значением данных
            case 9:break;                                             // Удалить узел с указанным порядковым номером
            default : printf("Неизвестная команда!");break;
        }
    }
    return 0;
}