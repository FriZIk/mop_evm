#include <stdio.h>

// Программная модель машины Тьюринга для индивидуального задания по МОИП(сиаод)

struct List
{
    int data;
    struct List *prev;
    struct List *next;
};
typedef struct List List;

void InitList(List **node)
{
    (*node) = (List*)malloc(sizeof(List));
    (*node)->data = NULL;
    (*node)->prev = NULL;
    (*node)->next = NULL;
}

int main()
{
    printf("Машина тьюринга!\n");
    List *tur;

    

    return 0;
}
