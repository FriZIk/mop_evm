#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>  //Для sleep

#define DEBUG 0

// Двусвязный список для представления ленты машины Тьюринга
struct List
{
    struct List *prev;
    struct List *next;
    char data; 
};
typedef struct List List;

// Структура данных для представления ячейки в таблице команд
struct Command
{
    char NewSymbol; // Какой символ ставится в текущую ячейку
    char Displacement;  // В какую сторону сместиться 
    int NewState; // В какое состояние переходи машина
};
typedef struct Command Command;

Command** GetCommands(int *CntOfLines,int *CntOfColums)
{
    FILE *CommandsFile = fopen("commands.txt","rt");
    int CountOfLines,CountOfColums;
    fscanf(CommandsFile,"%d %d",&CountOfLines,&CountOfColums);
    
    Command **cmd = (Command**)malloc(sizeof(Command*) * CountOfLines);
    for(int i =0;i < CountOfLines;i++)
        cmd[i] = (Command*)malloc(sizeof(Command) * CountOfColums);
    
    for(int i = 0;i < CountOfLines;i++)
    {
        for(int j = 0;j <= CountOfColums;j++)
        {
            char str[10];
            fscanf(CommandsFile,"%s",str);
            if(DEBUG)printf("%-5s ",str);
            
            cmd[i][j].NewSymbol = str[0];
            cmd[i][j].Displacement = str[1];
            if(strlen(str) - 2 == 1)cmd[i][j].NewState = str[2] - 48; 
            else if(strlen(str) - 2 == 2)cmd[i][j].NewState = (str[2]-48)*10 + (str[3]-48);
        }
        if(DEBUG)printf("\n");
    }
    if(DEBUG)
    {
        printf("\n");
        for(int i = 0;i < CountOfLines;i++)
        {
            for(int j = 1;j <= CountOfColums;j++)
            {
                if(cmd[i][j].NewSymbol == '0') printf("       ");
                else printf("%c%c%d    ",cmd[i][j].NewSymbol,cmd[i][j].Displacement,cmd[i][j].NewState);
            }
            printf("\n");
        }
    }
    *CntOfLines = CountOfLines;
    *CntOfColums = CountOfColums;
    return cmd;
}

// функция сравнения введённой строки с шаблоном 11...111-111...1+11..1
int CheckTemplate(char *str,int len) 
{
    int i = 0;
    int temp_i = i;
    int lenCounter1 = 0,lenCounter2 = 0;
    for(i;str[i] == '1';i++,lenCounter1++)
        if(DEBUG)printf("%c",str[i]);
    if(temp_i != i)
    {
        if(str[i] != '-')return 0; // Строка не подходит под шаблона
        else
        {
            if(DEBUG)printf("%c",str[i]);
            i++; 
            int temp_i = i; 
            for(i;str[i] == '1';i++,lenCounter2++)
                if(DEBUG)printf("%c",str[i]);
            if(temp_i == i || lenCounter1 <= lenCounter2) return 0; // Строка не подходит, так как после минуса сразу идёт плюс
            else
            {
                if(str[i] != '+')return 0; // Строка не подходит под шаблона
                else
                {
                    if(DEBUG)printf("%c",str[i]);
                    i++;
                    temp_i = i;
                    for(i;str[i] == '1';i++)
                        if(DEBUG)printf("%c",str[i]);
                    if(temp_i == i)return 0; // Строка не подходит под шаблона
                    else return 1;
                }
                
            }
        }
    }
    else return 0; // Строка не подходит, так как нет единиц    
}

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
}

void PrintList(List *ptr,int len,int ColorIndex,int State)
{
    printf("(%d) ",State);
    for(int i = 0;i < len && ptr->next != NULL;i++)
    {
        if(ColorIndex < 0) ColorIndex = 0;
        if(i == ColorIndex) printf("\033[31m%c\033[0m",ptr->data);
        else printf("%c",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    //printf("\033[31mThis is red.\033[0m\n");
    printf("Загрузка таблицы команд...");
    int CountOfLines,CountOfColums;
    Command **ComTable = GetCommands(&CountOfLines,&CountOfColums);
    printf("Успешно\nАлфавит - %d команд,количество состояний - %d\n",CountOfLines,CountOfColums);
    
    //printf("%d %d\n",CountOfLines,CountOfColums);
    if(DEBUG)
    {
        for(int i = 0;i < CountOfLines;i++)
        {
            for(int j = 1;j <= CountOfColums;j++)
            {
                if(ComTable[i][j].NewSymbol == '0') printf("       ");
                else printf("%c%c%d    ",ComTable[i][j].NewSymbol,ComTable[i][j].Displacement,ComTable[i][j].NewState);
            }
            printf("\n");
        }
    }

    const int n = 100;
    char str[n];
    printf("Введите начально состояние ленты:");
    scanf("%s",str);
    printf("Проверка введённой строки на соответсвие шаблону...");
    int len = strlen(str);

    //Проверка введённой строки по шаблону
    if(CheckTemplate(str,len) == 1)printf("введённая строка соответствует шаблону\n");
    else 
    {
        printf("введённая строка не соответствует шаблону!\n");
        return 0;
    }

    // Активировать ли задержку?
    int choose;
    printf("Активировать задержку?(1,0):");
    scanf("%d",&choose);

    //Переводим введённую строку в двусвязынй список
    List *ptr,*Head;
    Head = InitList(); // инициализация головы списка
    ptr = Head;
    StringToList(str,ptr,Head);

    if(DEBUG)
    {
        for(int i = 0;i < len && ptr->next != NULL;i++)
        {
            printf("%c",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    
    
    // Основной цикл программы
    int CurrentState = 1; // Переменная для храненния текущего состояния машины
    ptr = Head; // Переводим указатель на голову списка (на первый элемент)
    int ColorIndex = 0; // Счётчик для покраски

    while(CurrentState != 0)
    {
        // Печать текущей ленты
        if(ptr->next != NULL)PrintList(Head,len,ColorIndex,CurrentState);
        int IndexSymbol;

        // Замена знчение на индексы в массиве команд
        switch(ptr->data)
        {
            case '1':IndexSymbol = 0;break;
            case '-':IndexSymbol = 1;break;
            case '+':IndexSymbol = 2;break;
            case 'a':IndexSymbol = 3;break;
            case 'b':IndexSymbol = 4;break;
            case '=':IndexSymbol = 5;break;
            case '#':IndexSymbol = 6;break;
        }
        if(DEBUG)
        {
            printf("%d %c %d\n",CurrentState,ptr->data,IndexSymbol);
            printf("%c%c%d",ComTable[IndexSymbol][CurrentState].NewSymbol,ComTable[IndexSymbol][CurrentState].Displacement,ComTable[IndexSymbol][CurrentState].NewState);
        }
        ptr->data = ComTable[IndexSymbol][CurrentState].NewSymbol; // Замена символа в соответсвие с командой
        
        switch(ComTable[IndexSymbol][CurrentState].Displacement) // Куда движемся?
        {
            case '>':
                if(ptr->next != NULL)
                {
                    ptr = ptr->next;
                    ColorIndex++;
                }
                else
                {
                    ptr->next = InitList();
                    ptr->next->prev = ptr;
                    //ptr = ptr->next;
                    ptr->data = '#';
                    len++;
                }
            break;
            
            case '<':
                if(ptr->prev != NULL)
                {
                    ptr = ptr->prev;
                    ColorIndex--;
                }
                else
                {
                    ptr->prev = InitList();
                    ptr->prev->next = ptr;
                    ptr = ptr->prev;
                    ptr->data = '#';
                    len++;
                    ColorIndex--;
                    Head=ptr;
                }
            break;

            case '.':ptr = ptr;break;
            //default:printf("Неизвестная ошибка\n");break;
        }
        CurrentState = ComTable[IndexSymbol][CurrentState].NewState; // Новое состояние машины
        if(ptr->next != NULL && choose == 1)sleep(1);
    }
    ptr = Head;
    printf("Результат работы алгоритма:");
    for(int i = 0;i < len;i++)
    {
        if(ptr->data != '#')printf("%c",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return 0;
}
// вариант задания 4 - 26 
//https://docs.google.com/spreadsheets/d/10sleJKVNywEWFeAI8AHPcQI7Ml6d20z4qeU7NCDKa4s/edit#gid=275715656