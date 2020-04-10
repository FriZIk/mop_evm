#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void A() // Сумма элементов
{
    const int n1 = 1000;
    int a[n1],n = 0;
    scanf("%d",&n);

    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);

    int sum = 0;
    for(int i = 0;i < n;i++)
        sum = sum + a[i];
    printf("%d",sum);
}

int B() // номер числа фибоначи
{
    const int n = 10;
    int farray[n];
    farray[0] = 1;
    farray[1] = 2;

    // Получили массив чисел фибоначи до 10 числа
    for(int i = 2;i < n;i++)
        farray[i] = farray[i - 1] + farray[i - 2];

    for(int i = 0;i < n;i++)
        printf("%d ",farray[i]);

    printf("\n");
    int a = 0;
    scanf("%d",&a);
    for(int i = 0;i < n;i++)
        if(farray[i] == a)printf("%d",i + 1);
}

int SearchWords(char *str,int FirstSymbol,int LastSymbol,int count,int *StartNewWord) 
{
   for(int i = FirstSymbol;i < LastSymbol;i++)
    {
        if(str[i] == ' ' && *StartNewWord == 0)
        {
            *StartNewWord = 1;
            count++;
        }
        if(str[i] != ' ' && *StartNewWord == 1)
        {
            *StartNewWord = 0;
        }
    }
    return count;
}

// Подсчёт количества строк в строке
int C()
{
    const int n = 100;
    char str[n];
    fgets(str,n,stdin);
    int len = strlen(str);

    // Отсекание лишних пробелов
    int FirstSymbol = 0;
    int LastSymbol = len - 2;
    for(FirstSymbol;str[FirstSymbol] == ' ';FirstSymbol++);
    printf("%d ",FirstSymbol);
    for(LastSymbol;str[LastSymbol] == ' ';LastSymbol--);
    printf("%d ",LastSymbol);

    // Основной блок программы
    int StartNewWord = 0;
    int count;
    if(LastSymbol < 0)count = 0;
    else count = 1;
    count = SearchWords(str,FirstSymbol,LastSymbol,count,&StartNewWord);
    printf("\nКоличество слов(2 способ):%d\n",count);
}

struct Student
{
    char Surname[30];
    int Age;
};

int compare_ints(const void* a, const void* b) // Для квик сорта
{
    const int *arg1 = a;
    const int *arg2 = b;
    return *arg1 - *arg2;
}

void D()
{
    int n;
    
    FILE *InputFile = fopen("input.txt","rt");
    fscanf(InputFile,"%d",&n);  
    typedef struct Student Student;
    Student *Students = (Student*)calloc(n,sizeof(Student));
    for(int i = 0;i < n;i++)
        fscanf(InputFile,"%s %d",&Students[i].Surname,&Students[i].Age);
    fclose(InputFile);

    // Сортировка сначала по возрасту, тупо пузырьком если что с квик сортом разберёмся принцип там тот же
    for(int i = 0;i < n - 1;i++)
    {
        for(int j = i + 1;j < n;j++)
        {
            if(Students[i].Age < Students[j].Age)
            {
                Student temp = Students[i];
                Students[i]= Students[j];
                Students[j] = temp;
            }
        }
    }
    
    // Сортировка в лексикографическом порядке
    for(int i = 0;i < n - 1;i++)
    {
        for(int j = i + 1;j < n;j++)
        {
            if(strncmp(Students[i].Surname,Students[j].Surname,strlen(Students[i].Surname)) > 0)
            {
                Student temp = Students[i];
                Students[i]= Students[j];
                Students[j] = temp;
            }
        }
    }
    

    // Сортировка квик сортом не работает
    //qsort(Students, n, sizeof(Students), compare_ints);

    FILE *OutputFile = fopen("output.txt","wt");
    for(int i = 0;i < n;i++)
        fprintf(OutputFile,"%s %d\n",Students[i].Surname,Students[i].Age);
    fclose(OutputFile);
    free(Students);
}

void E()
{
    int a;
    const n = 1000;
    printf("Введите число для проверки на простоту:");
    scanf("%d",&a);
    // Определим, является ли число простым
    int countd = 0;
    for(int i = 1;i <= n && i <= a;i++)
        if(a % i == 0)countd++; 
    if(countd - 1 == 1 || a == 1) // Если число простое будем искать его номер
    {
        printf("Число %d простое\n",a);
        int array[n],Index = 0;
        int triger = 0;
        for(int i = 1;i < n;i++)
        {
            triger = 0;
            for(int j = 1;j < n;j++)
            {
                if(i % j == 0)triger++;
            }
            if(triger == 2)
            {
                array[Index] = i;
                Index++;
            }
        }

        printf("--------------------------------------------\n");
        // Начинаем сравнивать и ищем нужный индекс
        for(int i = 0;i < Index;i++)
            if(array[i] == a)printf("Номер в списке простых:%d",i + 1);

        printf("\nВсе простые числа до %d :",a);
        // Выводим все простые числа до 5 
        for(int i = 0;array[i] <= a;i++)
            printf("%d ",array[i]);
    }
    else // Если число составное будем искать ближайшее простое
    {
        printf("Число %d составное\n",a);
        // на самом деле не намного сложнее то же самое по сути своей не хочу делать это просто мартышкин труд
    }
    // Найдем ближайшее к a просто число
}

int main()
{
    int choose;
    printf("Введите номер команды:");
    scanf("%d",&choose);
    switch(choose)
    {
        case 1:A();break; // Самая тупая
        case 2:B();break; // На саомм деле не сложно
        case 3:C();break; // Лучше отдельно запускать
        case 4:D();break; // Самая сложная
        case 5:E();break; // Определение простоты числа
        default: printf("That are fuck you doing??\n"); 
    }
    return 0;
}