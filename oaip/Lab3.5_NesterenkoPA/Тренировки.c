#include <stdio.h>
#include <string.h>

int A(int chislo)// Проверка числа на простоту
{
    int a = 0;
    scanf("%d",&a);
    if(a == 0 || a == 1)return 1;// Число простое
    else
    { 
        int n = 2;
        while(a % n != 0)n++;
        if(n != a)return 0; // Число составное
        else return 1; // Число простое
    }
}

void B()// Нахождение k-го простотого числа
{
    const int n = 100000;
    int a[n];// Массив простых чисел
    int k; // Номер числа для поиска
    scanf("%d",&k);
    int chislo = 1,i = 0;
    while(i < k)
    {
        int result = A(chislo);
        printf("%d",chislo);
        if(result == 1)
        {
            a[i] = chislo;
            i++;
        }
        chislo++;
    }

    for(int i = 0;i < k;i++)printf("%d",a[i]);
}

void C()// Нахождение кол-ва слов в строке
{
    const int n = 10000;
    char str[n];
    fgets(str,n,stdin);
    char *p_str = str;
    int len = 0;
    for(p_str;*p_str;p_str++,len++);
    len = len -1;
    printf("Длинна строки:%d\n",len);
    int triger_zeros = 0,triger_no_zeros = 0;
    int CountOfWords = 0;
    for(int  i = 0;i < len;i++)
    {
        if(str[i] == ' ')
        {
            if(triger_zeros != 1)
            {
                if(triger_no_zeros != 0)
                {
                    printf("\n");
                    triger_zeros = 1;//Чтобы вывод пробелов не повторялся
                    triger_no_zeros = 0;
                }
            }
        }
        else 
        {
            printf("%c",str[i]);
            if(triger_no_zeros == 0)
            {
                CountOfWords++;
                triger_no_zeros = 1;
            }
            triger_no_zeros = 1;//Найдено новое слово
            triger_zeros = 0;
        }
    }
    printf("\nКол-во слов:%d",CountOfWords);
    printf("\n");
}

void D()// Нахождение подстроки в строке
{
    const int n = 255;
    char str[n],str1[n];
    printf("Введите основную строку:");
    fgets(str,n,stdin);
    printf("Введите подстроку:");
    fgets(str1,n,stdin);
    char *ptr_str = str,*ptr_str1 = str1;
    int len = 0,len1 = 0;
    for(ptr_str;*ptr_str;ptr_str++,len++);
    for(ptr_str1;*ptr_str1;ptr_str1++,len1++);
    len = len - 1;// Один симввол на \n
    len1 = len1 - 1;
    printf("Длинна основной строки:%d\n",len);
    printf("Длинна подстроки:%d\n",len1);

    int EnterTriger = 0;
    int StartIndex = 0,FinishIndex = 0;

    // Теоретически такая конструкция должна тоже работать однако это не так
    /*char *ptr_str_result = strstr(str,str1);
    if(ptr_str_result == NULL)printf("Нет вхождения!");
    else printf("Подстрока найдена!");*/

    for(int i = 0;i < len;i++)
    {
        if(str[i] == str1[0])
        {
            //printf("%c %c\n",str[i],str1[0]);
            int count = 0,pointer = 0;
            if(len1 == 1)EnterTriger = 1;
            else
            {
                for(int j = i;j < i+len1;j++)
                {
                    //printf("%c %c\n",str[j],str1[pointer]);
                    if(str[j] == str1[pointer])count++;
                    pointer++;
                }
                //printf("Длина искомой и найденной строки:%d %d\n",count,len1);
                if(count == len1)EnterTriger = 1;
                else EnterTriger = 0; 
            }
            
        }
    }
    
    if(EnterTriger == 0)printf("Вхождения нет!\n");
    else printf("В строке есть подстрока!\n");
}

void E()// Нужно дописать работу с массивами идексов эллементов они выводятся не в том порядке
{
     // Поиск седловых точек
    int n1,m1;
    const int n = 100,m = 10000;
    int a[n][m];
    scanf("%d %d",&m1,&n1);
    printf("\n");

    for(int i = 0;i < n1;i++)
        for(int j = 0;j < m1;j++)
            scanf("%d",&a[i][j]);
       
    printf("\n");
    // Находим минимумы строк
    int aMin[n][n];
    int count = 0;
    int min = 10001,mini,minj;
    for(int i = 0;i < n1;i++)
    {
        for(int j = 0;j < m1;j++)
        {
            if(a[i][j] < min)
            {
                min = a[i][j];
                mini = i;
                minj = j;
            }
        }
        aMin[0][i] = mini;
        aMin[1][i] = minj;
        min = 10001;
    }
    printf("Мнимумы строк (x,y):\n");
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < n1;j++)printf("%d ",aMin[i][j]);
        printf("\n");
    }
    printf("\n \n");

    // Находим максимумы столбцов
    int aMax[n][n];
    int max = -100001,maxi,maxj;
    for(int i = 0;i < m1;i++)
    {
        for(int j = 0;j < n1;j++)
        {
            if(a[j][i] > max)
            {
                max = a[j][i];
                maxi = i;
                maxj = j;
            }
        }
        aMax[i][0] = maxj;
        aMax[i][1] = maxi;
        max = -100001; 
    }

    printf("Максимумы строк (x,y):\n");
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < m1;j++)printf("%d ",aMax[i][j]);
        printf("\n");
    }
    printf("\n");

    int triger = 0;
    for(int i = 0;i < n1;i++)
    {
        if(aMax[i][0] == aMin[i][0] && aMax[i][1] == aMin[i][1])printf("%d %d\n",aMax[i][0],aMin[i][1]);
        else 
        {
            if(triger != 1)
            {
                printf("0\n");
                triger = 1;
            }
        }        
    }
    printf("\n");
}

int main(void)
{
    // Спираль
    const int n = 20,m = 20;
    int a[n][m];
    int n1,m1;
    scanf("%d %d",&n1,&m1);

    for(int i = 0;i < n1;i++)
        for(int j = 0;j < m1;j++)
            a[i][j] = 0;

    int i = 0;
    int j = 0;
    for(i;i < n1;i++)a[0][i] = i + 1;

    a[2][i] = 5;
    a[1][i] = 6;
    a[0][i] = 7;

    for(int i = 0;i < n1;i++)
    {
        for(int j = 0;j < m1;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}