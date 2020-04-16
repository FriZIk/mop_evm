#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// вариант № 3

struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
    struct Tree *parent;
    int triger ;
};
typedef struct Tree Tree;

void InitRoot(Tree **root) // Инициализация дерева 
{
    (*root) = (Tree*)malloc(sizeof(Tree));
    (*root)->data = 123;
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->parent = NULL;
    (*root)->triger = 0;
}

void PrintTree(Tree *root) // Вывод содержимого дерева
{
    if(root != NULL)
    {
        printf("%d ",root->data); 
        PrintTree(root->left); 
        PrintTree(root->right);
    }
}

void PrintTreeNoRec(Tree *root)
{
    printf("%d ",root->data);
    int TrigerToStop = 0;
    do
    {
        if(root->parent == NULL && root->left->triger == 1 && root->right->triger == 1)
            TrigerToStop = 1;
        else
        {
            if(root->left != NULL && root->left->triger == 0)
            {
                root = root->left;
                printf("%d ",root->data);
                root->triger = 1;
            }
            else if(root->right != NULL && root->right->triger == 0)
            {
                root = root->right;
                printf("%d ",root->data);
                root->triger = 1;
            }
            else root = root->parent;
        }
    }while(TrigerToStop == 0);
}


Tree* EnterTreeELement(Tree *root, int var,Tree *prev) // Ввода дерева
{
    if(root == NULL) // Если дошли в рекурсии до элемнета, который ещё не инициализирован, то стоп рекурсии.
    {
        root = (Tree*)malloc(sizeof(Tree));
        root->data = var;
        root->left = NULL;
        root->right = NULL;
        root->parent = prev;
        root->triger = 0;
    }
    else if(root->data > var)
    {
        prev = root;
        root->left = EnterTreeELement(root->left,var,prev);
    }
    else
    {
        prev = root;
        root-> right = EnterTreeELement(root->right,var,prev);
    }       
    return root;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    int command = -1;
    Tree *root = NULL;
    int var;
    printf("Дотсупные команды:\n1) Инициализация дерева\n2) Добавление нового элемента в дерево\n3) Вывод текущего дерева\n4) Вывод сцепленного представления дерева\n");
    while(command != 0)
    {
        printf(">>>");
        scanf("%d",&command);
        switch(command)
        {
            case 0:break;                                                       // Остановка работы программы
            case 1:                                                             // Инициализируем корень
                InitRoot(&root);                                              
                printf("Корень дерева инициализирован!\n");
            break; 
            case 2:                                                             // Добавление нового элемента в дерево используя рекурсию
                printf("Введите новую переменную:");
                scanf("%d",&var);
                root = EnterTreeELement(root,var,root);
            break;
            case 3:                                                             // Вывод текущего дерева через рекурсию
                if(root == NULL)
                    printf("Дерево пустое, нет ни одной ячейки ");
                else
                {
                    printf("Текущщее дерево (через рекурсию):");
                    PrintTree(root);

                    printf("\nТекущщее дерево (чреез цикл):");
                    PrintTreeNoRec(root);
                    printf("\n");
                }
            break;
            case 4:/*is comming*/break;
            default:printf("Неизвестная команда, повторите попытку!\n");break;
        }
    }
    
    return 0;
}