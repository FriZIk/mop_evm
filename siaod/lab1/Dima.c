#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

struct list {
    struct list* next;
    struct list* prev;
    int value;
    int flag;
} list;
typedef struct list* List;

int menu(int l); void wh(); List initList(); List removeList(List head); List addToBegining(List head, int v); void show(List head);
List addToEnding(List head, int v); List removeFirstElem(List head); List removeLastElem(List head); List f1(List l1, List l2); List* f2(List *head1, List *head2);

int main()
{
    setlocale(LC_ALL, "rus");
    printf("\n\n\n\n");
    wh();
}

void wh() {
    List firstList = NULL;
    List secondList = NULL;

    int l = 1;
    while (1) {
        int o = menu(l);
        switch (o)
        {
            case 1:
                if (l == 1) {
                    if (firstList != NULL) {
                        printf("%s\n", "Список уже инициализирован");
                    }
                    else
                    {
                        firstList = initList();
                        printf("%s\n", "Список успешно инициализирован");
                    }
                    printf("\n");
                }
                else
                {
                    if (secondList != NULL) {
                        printf("\n%s\n", "Список уже инициализирован");
                    }
                    else
                    {
                        secondList = initList();
                        printf("%s\n", "Список успешно иницализирован");
                    }
                    printf("\n");
                }
                break;
            case 2:
                if (l == 1) {
                    if (firstList == NULL) {
                        printf("%s\n", "Список не инициализирован");
                    }
                    else {
                        firstList = removeList(firstList);
                       
                        printf("%s\n", "Список успешно удален");
                    }
                    printf("\n");
                }
                else
                {
                    if (secondList == NULL) {
                        printf("%s\n", "Список не инициализирован");
                    }
                    else {
                        secondList = removeList(secondList);
                       
                        printf("%s\n", "Список успешно удален");
                    }
                    printf("\n");
                }
                break;
            case 11:
                l = 1;
                printf("%s\n", "Выбран первый список");
                printf("\n");
                break;
            case 22:
                l = 2;
                printf("%s\n", "Выбран второй список");
                printf("\n");
                break;
            case 9:
                if (l == 1) {
                    if (firstList == NULL)
                        printf("%s\n", "Список не инициализирован");
                    else
                        show(firstList);
                    printf("\n");
                }
                else {
                    if (secondList == NULL)
                        printf("%s\n", "Список не инициализирован");
                    else
                        show(secondList);
                    
                }
                printf("\n");
                break;
            case 3:
                if (l == 1) {
                    if (firstList == NULL)
                        printf("%s\n", "Список не инициализирован");
                    else {
                        int o;
                        printf("%s\n%s", "Введите значение нового элемента", ">> ");
                        scanf("%d", &o);
                        firstList = addToBegining(firstList, o);
                        printf("%s\n","Элемент успешно добавлен");
                    }
                }
                else {
                    if (secondList == NULL)
                        printf("%s\n", "Список не инициализирован");
                    else {
                        int o;
                        printf("%s\n%s", "Введите значение нового элемента", ">> ");
                        scanf("%d", &o);
                        secondList = addToBegining(secondList, o);
                        printf("%s\n", "Элемент успешно добавлен");
                    }
                }
                printf("\n");
                break;
            case 4:
                if (l == 1) {
                    if (firstList == NULL)
                        printf("%s\n", "Список не инициализирован");
                    else {
                        int o;
                        printf("%s\n%s", "Введите значение нового элемента", ">> ");
                        scanf("%d", &o);
                        firstList = addToEnding(firstList, o);
                        printf("%s\n", "Элемент успешно добавлен");
                    }
                }
                else {
                    if (secondList == NULL)
                        printf("%s\n", "Список не инициализирован");
                    else {
                        int o;
                        printf("%s\n%s", "Введите значение нового элемента", ">> ");
                        scanf("%d", &o);
                        secondList = addToEnding(secondList, o);
                        printf("%s\n", "Элемент успешно добавлен");
                    }
                }
                printf("\n");
                break;
            case 5:
                if (l == 1) {
                    if (firstList == NULL)
                        printf("%s\n", "Список не инициализирован");
                    else {
                        if (firstList->flag == 0) {
                            printf("%s\n", "Список пуст");
                        }
                        else {
                            firstList = removeFirstElem(firstList);
                            printf("%s\n", "Элемент успешно удален");
                        }
                    }
                }
                else {
                    if (secondList == NULL)
                        printf("%s\n", "Список не инициализирован");
                    else {
                        if (secondList->flag == 0) {
                            printf("%s\n", "Список пуст");
                        }
                        else {
                            secondList = removeFirstElem(secondList);
                            printf("%s\n", "Элемент успешно удален");
                        }
                    }
                }
                printf("\n");
                break;
            case 6:
                if (l == 1) {
                    if (firstList == NULL)
                        printf("%s\n", "Список не инициализирован");
                    else {
                        if (firstList->flag == 0) {
                            printf("%s\n", "Список пуст");
                        }
                        else {
                            firstList = removeLastElem(firstList);
                            printf("%s\n", "Элемент успешно удален");
                        }
                    }
                    printf("\n");
                }
                else {
                    if (secondList == NULL)
                        printf("%s\n", "Список не инициализирован");
                    else {
                        if (secondList->flag == 0) {
                            printf("%s\n", "Список пуст");
                        }
                        else {
                            secondList = removeLastElem(secondList);
                            printf("%s\n", "Элемент успешно удален");
                        }
                    }
                    printf("\n");
                }
                break;
            case 7 :
                if (firstList == NULL || secondList == NULL) {
                    printf("%s\n\n", "Один из списков не инициализирован!");
                    break;
                } else
                if (l == 1) {
                    firstList = f1(firstList, secondList);
                }
                else {
                    secondList = f1(secondList, firstList);
                }
                printf("%s\n\n","Список успешно скопирован");
                break;
            case 8:
                    if (l == 1) {
                        if (firstList == NULL) {
                            printf("%s\n\n", "Список не инициализирован!");
                            break;
                        }
                        secondList = *f2(&firstList, &secondList);
                    }
                    else {
                        if (secondList == NULL) {
                            printf("%s\n\n", "Список не инициализирован!");
                            break;
                        }
                        firstList = *f2(&secondList, &firstList);
                    printf("\n%s\n\n", "Элементы успешно перенесены в соседний список");
                }
                break;
            case 0:
                printf("\n%s\n", "Удаление списков...");
                if (firstList != NULL) 
                    removeList(firstList);
                
                if (secondList != NULL)
                    removeList(secondList);
                printf("\n%s\n", "Списки удалены");
                return;
        default:
            printf("%s\n", "Введено неверное значение");
        }
    }
}

int menu(int l) {
    printf("%s%d\n\n", "Текущий лист - ",l);
    printf("%s\n", "1 - Инициализация списка");
    printf("%s\n", "2 - Удаление списка");
    printf("%s\n", "3 - Добавить элемент в начало списка");
    printf("%s\n", "4 - Добавить элемент в конец списка");
    printf("%s\n", "5 - Удалить элемент из начала списка");
    printf("%s\n", "6 - Удалить элемент из конца списка");
    printf("%s\n", "7 - Добавить (скопировать) один список в хвост второго");
    printf("%s\n", "8 - Перенести(не копируя) все четные по порядку узлы в отдельный список");
    printf("%s\n", "9 - Вывод списка");
    printf("%s\n", "0 - Выход");
    printf("\n");
    printf("%s\n", "11 - Выбор первого списка");
    printf("%s\n", "22 - Выбор второго списка");
    printf("\n%s", ">> ");
    int i = -1;
    scanf("%d", &i);
    system("cls");
    printf("%s%d\n\n",">> ", i);
    return i;
}

List initList() {
    List l = (List) malloc(sizeof(struct list));
    l->next = l;
    l->prev = l;
    l->flag = 0;
    l->value = NULL;
    return l;
}

List removeList(List head) {
   
    while (head!=NULL)
    {
        List l = head->next;
        if (head != l) {
            head->next = l->next;
            l->next->prev = head;
            free(l);
        }
        else {
            free(head);
            head = NULL;
        }
    }
    return head;
}

List addToBegining(List head, int v) {
    
    if (head->flag==1) {
        List neW = (List)malloc(sizeof(struct list));
        neW->next = head;
        head->prev->next = neW;
        neW->prev = head->prev;
        head->prev = neW;
        neW->value = v;
        head = neW;
        head->flag = 1;
    }
    else {
        head->value = v;
        head->flag = 1;
    }
    return head;
}

void show(List head) {
    List p = head;
    printf("%s\n",">>");
    while ((p->next != head)){
        printf("%d\n", p->value);
        p = p->next;
    } 
        if (head->flag==1)
            printf("%d\n", p->value);
    printf("%s\n","<<");
}

List addToEnding(List head, int v) {
    if (head->flag == 0)
    {
        head->value = v;
        head->flag = 1;
    }
    else
    {
        List neW = (List)malloc(sizeof(struct list));
        neW->next = head;
        head->prev->next = neW;
        neW->prev = head->prev;
        head->prev = neW;
        neW->value = v;
    }
    return head;
}

List removeFirstElem(List head) {
    List d = head;
    if (head == head->next) {
        head->value= NULL;
        head->flag = 0;
    }
    else {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        free(d);
    }
    return head;
}

List removeLastElem(List head) {
    List d = head->prev;
    if (head == head->next) {
        head->value = NULL;
        head->flag = 0;
    }
    else {
        head->prev = head->prev->prev;
        d->prev->next = head;
        free(d);
    }
    return head;
}

List f1(List l1, List l2) {
    List p1 = l2->next;

    l1 = addToEnding(l1, l2->value);
    while (p1 != l2) {
        l1 = addToEnding(l1, p1->value);
        p1 = p1->next;
    }
    return l1;
}

 List* f2(List* hhead1, List* hhead2) {
     List head1 = *hhead1;
     List head2 = *hhead2;
     removeList(head2);
     head2 = initList(head2);
     List a = head1;
     List b = head1->next;
     List c = b->next;
     List p2;
     List h2;
     a->next = c;
     c->prev = a;
     head2 = b;
     b->next = b;
     b->prev = b;
     p2 = head2;
     while (a->next != head1 && c->next != head1) {
         a = c;
         b = a->next;
         c = b->next;
         a->next = c;
         c->prev = a;
         h2 = b;
         p2->next = h2;
         head2->prev = h2;
         h2->prev = p2;
         h2->next = head2;
         p2 = p2->next;
     }
     head2->flag = 1;
     hhead2 = &head2;
     return hhead2;
}