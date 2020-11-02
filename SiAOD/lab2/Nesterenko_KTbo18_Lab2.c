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
    printf("Введите значение для корня дерева:");
    int var = 0;
    scanf("%d",&var);
    (*root)->data = var;
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->parent = NULL;
    (*root)->triger = 0;
}

void PrintTree(Tree *root) // Вывод содержимого дерева рекурсивно
{
    if(root != NULL)
    {
        printf("%d ",root->data); 
        PrintTree(root->left); 
        PrintTree(root->right);
    }
}

void ClearTrigers(Tree *root) // Функция для отчистки тригеров после вывода не через рекурсию
{
    if(root != NULL)
    {
        root->triger = 0;
        ClearTrigers(root->left);
        ClearTrigers(root->right);
    }
}

Tree* EnterTreeELement(Tree *root, int var,Tree *prev) // Ввода элемента дерева рекурсивно
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

int ReplacementRec(Tree *root) // Функция замены через рекурсию
{
	if (root == NULL)
	{
		return 0;
	}
	else if ((root->left == NULL)&& (root->right == NULL))
	{
		return root->data;
	}
	else 
	{
		root->data = ReplacementRec(root->left) + ReplacementRec(root->right) + root->data;
		return root->data;
	}
}

struct stack // Структура стека для нерекурсивного обхода
{
	Tree *node;
	struct stack *next;
};
typedef struct stack stack;

void ClearStack(stack *node) // Процедура удаления стека
{
	while (node != NULL)
	{
		stack *t = node;
		node = node->next;
		free(t);
	}
	node = NULL;
}

Tree* stack_pop(stack *stackPtr) // Процедура добавления элемента в стек
{
	Tree *retVal = stackPtr->node;
	stack *nextOne = stackPtr->next;
	if (nextOne == NULL) ;
	else (*stackPtr) = (*nextOne);
	return retVal;
}

stack* stack_push(stack* stackPtr, Tree* node) // Процедура взятия элемента из стека
{
	stack *newItem;
	newItem = (stack*)malloc(sizeof(stack));
	if(newItem == NULL)
	{
		printf("Ошибка, закончилась память!\n");
		return;
	}
	else
	{
		newItem->next = stackPtr;
		newItem->node = node;
		return newItem;	
	}
}

void ReplacementNoRec(Tree *root) // Функция замены без рекурсии через стек
{
	Tree *currNode = root;
	stack *myStack = (stack*)calloc(1, sizeof(stack));
	myStack->node = NULL;
	myStack->next = NULL;
	int counter = 2;

	while (counter)
	{
		if (currNode == NULL || currNode == root)
		{
			counter--;
			if (counter == 0)continue;
		}
		if (currNode->left != NULL && currNode->left->triger == 0)
		{
			myStack = stack_push(myStack, currNode);
			currNode = currNode->left;
			continue;
		}
		if (currNode->right != NULL && currNode->right->triger == 0)
		{
			myStack = stack_push(myStack, currNode);
			currNode = currNode->right;
			continue;
		}
  		if ((currNode->left == NULL || currNode->right == NULL) ||(currNode->left->triger == 1 || currNode->left->triger == 1))
		{
			if (currNode->parent->right == currNode)
			{
				Tree *poppedNode = stack_pop(myStack);
				if (poppedNode == currNode->parent->left)
				{
					Tree *poppedParent = stack_pop(myStack);
					poppedParent->data = currNode->data + poppedNode->data + poppedParent->data;

					poppedNode->triger = 1;
					poppedParent->triger = 1;
					currNode->triger = 1;
					currNode = poppedParent;
					continue;
				}
				else
				{
					poppedNode->data = currNode->data + poppedNode->data;
					poppedNode->triger = 1;
					currNode->triger = 1;
					currNode = poppedNode;
					continue;
				}					
			}

			if (currNode->parent->left == currNode)
			{
				if (currNode->parent->right != NULL)
				{
					if (currNode->parent->right->triger)
					{
						Tree *poppedPar = stack_pop(myStack);
						currNode->triger = 1;
						poppedPar->data = currNode->data + currNode->parent->right->data  + poppedPar->data;
						poppedPar->triger = 1;
						currNode = poppedPar;
						continue;
					}
					else
					{
						myStack = stack_push(myStack, currNode);
						currNode = currNode->parent->right;
						continue;
					}
				}
				else
				{
					Tree *poppedPar = stack_pop(myStack);
					currNode->triger = 1;
					poppedPar->data = currNode->data + poppedPar->data;
					poppedPar->triger = 1;
					currNode = poppedPar;
					continue;
				}
			}
		}	
	}
	ClearStack(myStack);
}

int main()
{
    setlocale(LC_ALL,"Russian");
    int command = -1;
    Tree *root = NULL;
    int var,sum = 0;

    printf("Дотсупные команды:\n1) Инициализация дерева\n2) Добавление нового элемента в дерево\n3) Вывод текущего дерева\n4) Вывод сцепленного представления дерева\n5) Заменить значения каждой внутренней вершины суммой значений всех её потомков(рекурсивно)\n");
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
                    ClearTrigers(root);
                    printf("Текущщее дерево (через рекурсию):");
                    PrintTree(root);
                    printf("\n");
                }
            break;
            case 4:																// Замменить значения каждой внутр ... без рекурсии
                ClearTrigers(root);
                printf("Все значнения были заменены на суммы значений их потомков\n");
                ReplacementNoRec(root);
            break;                                     
            case 5:                                                             // Заменить значения каждой внутренней вершины суммой значений всех потомков
                printf("Все значения были заменены на суммы значений их потомков\n");
                ReplacementRec(root);
            break;
            default:printf("Неизвестная команда, повторите попытку!\n");break;
        }
    }
    return 0;
}