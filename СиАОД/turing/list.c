#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Двусвязный список для представления ленты машины Тьюринга
struct List
{
    struct List *prev;
    struct List *next;
    char data; 
};
typedef struct List List;

// Функция для инициализации спсика
List* InitList()
{
    List *Head = (List*)malloc(sizeof(List));
    Head->prev = NULL;
    Head->next = NULL;
    Head->data = NULL;
    return Head;
}

// Функция для преобразования строки в список
void StringToList(char *str,List *ptr,List *Head)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++) 
    {
        ptr->data = str[i];
        ptr->next = InitList();
        ptr->next->prev = ptr;
        ptr = ptr->next;
    } 
    ptr = Head; 
    for(int i = 0;i < len && ptr->next != NULL;i++)
    {
        printf("%c",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    char str[100]; // Строка, которую будем преобразовывать в отдельные элементы спсика
    scanf("%s",str);

    List *ptr;
    List *Head;
    Head = InitList();
    ptr = Head;
    StringToList(str,ptr,Head);

    return 0;
}