/*
Южный федеральный университет, ИКТИБ, кафедра МОП ЭВМ
Группа: КТбо1-8 Нестеренко П.А
Задание: A - Мониторинг успеваемости
Дата: 05.12.2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct StudentsParametrs
{
    int Group;  
    char Name[33];
    char Surname[33];
    int Balls; 
    char Project[256];
};

void PrintFunc(int ControlBalls,int CountOfStudents,struct StudentsParametrs *Student)
{
    FILE *OutputFile = fopen("output.txt","wt");
    //FILE *OutputFile = stdout; 
    for(int i = 0; i < CountOfStudents;i++)
    { 
        if(i == CountOfStudents - 1)
        {
            if(Student[i].Balls >= ControlBalls)
            {
                if(Student[i].Balls >= 100)
                    fprintf(OutputFile,"%s %s (%d) %d",Student[i].Name,Student[i].Surname,Student[i].Group,Student[i].Balls);
                if(Student[i].Balls >= 10 && Student[i].Balls < 100)
                    fprintf(OutputFile,"%s %s (0%d) %d",Student[i].Name,Student[i].Surname,Student[i].Group,Student[i].Balls);
                if(Student[i].Balls < 10)
                    printf(OutputFile,"%s %s (00%d) %d",Student[i].Name,Student[i].Surname,Student[i].Group,Student[i].Balls);
            }   
        }
        else
        {
            if(Student[i].Balls >= ControlBalls)
            {
                if(Student[i].Balls >= 100)
                    fprintf(OutputFile,"%s %s (%d) %d\n",Student[i].Name,Student[i].Surname,Student[i].Group,Student[i].Balls);
                if(Student[i].Balls >= 10 && Student[i].Balls < 100)
                    fprintf(OutputFile,"%s %s (0%d) %d\n",Student[i].Name,Student[i].Surname,Student[i].Group,Student[i].Balls);
                if(Student[i].Balls < 10)
                    printf(OutputFile,"%s %s (00%d) %d\n",Student[i].Name,Student[i].Surname,Student[i].Group,Student[i].Balls);
            }
        }   
    }
    fclose(OutputFile);
}
int main()
{
    FILE *bd = fopen("input.txt","rt");
    int ControlBal = 0,CountOfStudents = 0;
    fscanf(bd,"%d  %d",&ControlBal,&CountOfStudents);
    //printf("Контрольный бал и кол-во студентов:%d,%d\n",ControlBal,CountOfStudents);
    struct StudentsParametrs *Student = (struct StudentsParametrs*)malloc(CountOfStudents * sizeof(struct StudentsParametrs));
    
    for(int i = 0; i < CountOfStudents;i++)
        fscanf(bd,"%d %s %s %d %s",&Student[i].Group,&Student[i].Name,&Student[i].Surname,&Student[i].Balls,&Student[i].Project);

    // Преобраззование всех строк в нижний регистр
    for(int i = 0;i < CountOfStudents;i++)
    {
        int Len1 = strlen(Student[i].Name);
        for(int j = 0;j < Len1;j++)
            Student[i].Name[j] = tolower(Student[i].Name[j]);

        int Len2 = strlen(Student[i].Surname);
        for(int j = 0;j < Len2;j++)
            Student[i].Surname[j] = tolower(Student[i].Surname[j]);

        int Len3 = strlen(Student[i].Project);
        for(int j = 0;j < Len3;j++)
            Student[i].Project[j] = tolower(Student[i].Project[j]);

        Student[i].Name[0] = toupper(Student[i].Name[0]);
        Student[i].Surname[0] = toupper(Student[i].Surname[0]);
        Student[i].Project[0] = toupper(Student[i].Project[0]);
    }
    // Лексикографическая сортировка

    for(int i = 0;i < CountOfStudents - 1;i++)
    {
        for(int j = i + 1;j < CountOfStudents;j++)
        {
            if(strlen(Student[i].Surname) == strlen(Student[j].Surname) && 
            strlen(Student[i].Name) == strlen(Student[j].Name) && 
            Student[i].Group == Student[j].Group)
            {
                if(Student[i].Balls < Student[j].Balls)
                {
                    struct StudentsParametrs Temp = Student[i];
                    Student[i] = Student[j];
                    Student[j] = Temp;
                }
            }
            if(strlen(Student[i].Surname) == strlen(Student[j].Surname) && 
            strlen(Student[i].Name) == strlen(Student[j].Name))
            {
                if(Student[i].Group > Student[j].Group)
                {
                    struct StudentsParametrs Temp = Student[i];
                    Student[i] = Student[j];
                    Student[j] = Temp;
                }
            }
            if(strlen(Student[i].Surname) == strlen(Student[j].Surname))
            {
                if(strlen(Student[i].Name) > strlen(Student[j].Name))
                {
                    struct StudentsParametrs Temp = Student[i];
                    Student[i] = Student[j];
                    Student[j] = Temp;
                }
            }
            if(strlen(Student[i].Surname) > strlen(Student[j].Surname))
            {
                struct StudentsParametrs Temp = Student[i];
                Student[i] = Student[j];
                Student[j] = Temp;
            }  
        }
    }

    PrintFunc(ControlBal,CountOfStudents,Student);
    free(Student);
    fclose(bd);
    return 0;
}
/*
Перед выполнением задания прочитайте условия заданий «Мониторинг успеваемости» и «Мониторинг проектов».

Студенческие команды каждого института/факультета ЮФУ выполняют проекты и защищают их перед экзаменационными комиссиями.

Для организации защит проектов каждый институт организует несколько «сессий защит» - т.е. выделяет несколько дат, во время которых все студенты этого института, завершившие работу над проектом, могут его защитить.

Перед администрацией вуза и дирекциями институтов стоит задача планирования «сессий защит». Для каждой даты защиты нужно определить:

— какие именно проекты должны защищаться в каждую дату (срок завершения которых позже предыдущей даты, но не позже текущей), численность команды, средний уровень успеваемости команды по программированию и сколько примерно времени нужно отвести на защиту проекта (правило: минимальное время на доклад - 1 минута, дополнительно по 1 минуте выделяется за каждые полные 10 дней продолжительности проекты);

— список студентов, которые выполняют тот или иной проект с привязкой к номеру их института/факультета. Если над проектом работают студенты разных институтов, то проект защищается в каждом институте отдельно всей командой разработчиков (при этом даты защит одного и того же проекта в разных институтах могут различаться).

Администрация ЮФУ хочет пригласить на защиты гостей: представителей работодателей, сотрудников министерства, коллег из других вузов (в том числе зарубежных). От точности построения расписания защит зависит репутация вуза.

Поскольку одним из студенческих проектов как раз и является «Построение расписания защит проектов» и выполняете его вы, то если вы поможете решить эту непростую задачу, то сделаете большой шаг к получению стипендии по итогам семестра, а если нет...

Входные данные
В первой строке и последующих N строках на вход подается количество студентов и информация о них в соответствии с описанием формата соответствующих данных в задании «Мониторинг успеваемости».

В следующей строке и последующих после нее W строках на вход подается количество проектов и информация о них в соответствии с описанием формата соответствующих данных в задании «Мониторинг проектов».

В следующей строке задается натуральное число T (1≤T<1000) - количество институтов/факультетов ЮФУ. Далее следуют T строк в которых записаны следующие данные об институтах (все поля разделены одним пробелом):

— Уникальный идентификатор института U (1≤U≤999);

— Наименование (строка из больших и маленьких латинских символов и знаков подчеркивания - до 30 символов);

— Кол-во RU дат защит проектов, которые назначил институт U (1<RU≤10);

— Последовательность из RU дат защит, назначенных в институте U, каждая в формате DD.MM.YYYY в соответствии с условным календарем ЮФУ (01≤DD≤30, 01≤MM≤12, 2000≤YYYY≤3000). Даты указаны в произвольном порядке (необязательно по возрастанию).

Выходные данные
Вывод должен быть организован в виде последовательности строк, имеющей иерархическую структуру. Уровень иерархии (вложенности) определяется количество точек («.») в начале строки. Строки с текущем уровнем вложенности относятся к ближайшей сверху записи с более высоким уровнем вложенности.

На первом, верхнем уровне иерархии (одна точка «.» в начале строки) вывести строки с информацией об институтах. Каждая строка (кроме точки) содержит следующие поля, разделенные одним пробелом: идентификатор института (3 цифры), название института (первая буква заглавная, остальные строчные), количество дат защит, суммарное количество защищаемых в институте во все даты проектов, количество защищающихся студентов на всех защитах (не студентов института, а именно выполнявших проект). Строки с информацией об институтах упорядочиваются по возрастанию идентификатора института;

На втором уровне иерархии (двe точки «..» в начале строки) вывести строки с информацией о датах защит по данному институту. Каждая строка (кроме точек) содержит следующие поля, разделенные пробелом: дата защиты в формате DD.MM.YYYY, количество защищаемых в эту дату проектов, количество защищающихся в эту дату студентов.

Строки упорядочены по возрастанию даты в календаре. Если в данную дату нет защит, то строка с информацией о дате защиты все равно выводится, а строки следующего уровня иерархии не выводятся.

На третьем уровне иерархии (три точки «...» в начале строки) вывести строки с информацией о тех проектах, которые защищаются в эту дату в этом институте. Формат вывода строк с информацией о проекте (после точек) и порядок их сортировки при выводе соответствует заданию «Мониторинг проектов».

Если данный проект никто не выбрал, то строка с информацией о проекте все равно выводится, а строки следующего уровня иерархии не выводятся.

На четвертом, последнем уровне иерархии (четыре точки «....» в начале строки) выводится список исполнителей проекта, которые защищаются в данном институте в данную дату по данному проекту. Формат вывода строк с информацией о студентах (после точек) и порядок их сортировки при выводе соответствует заданию «Мониторинг успеваемости».
*/



/*B
Перед выполнением задания прочитайте условие задания «Мониторинг успеваемости».

Студенты ЮФУ выполняют проекты. Каждый проект является оригинальным, его название не может дублироваться. Над каждым проектом работает одна единственная команда, в которую могут входить один или несколько студентов одного или нескольких институтов/факультетов ЮФУ. Независимо от того, студенты каких институтов входят в команду проекта, каждый проект завершается защитой в том институте, сотрудники которого предложили тему проекта (даже если ни один студент этого института над проектом не работал).

Поскольку проектная деятельность - это один из современных трендов обучения, в ЮФУ пришло указание из министерства провести мониторинг выполняемых проектов и оценить, сколько студентов какого института/факультета работают над каждым из проектов и какова продолжительность выполнения каждого проекта.

Помогите администрации ЮФУ решить эту задачу.

Входные данные
В первой строке и последующих N строках на вход подается количество студентов и информация о них в соответствии с описанием формата соответствующих данных в задании «Мониторинг успеваемости».

Далее указано число различных проектов W (0<W≤100). В следующих W строках приведена информация о проектах:

— Уникальный идентификатор института u, в котором защищается проект (1≤u≤999);

— Название проекта (последовательность больших и маленьких латинских букв и символов подчеркивания длиной не более 255 символов каждая);

— Дата выдачи задания на проект в формате DD:MM:YYYY в соответствии с условным календарем ЮФУ (01≤DD≤30, 01≤MM≤12, 2000≤YYYY≤3000);

— Дата сдачи проекта в формате DD:MM:YYYY в соответствии с календарем ЮФУ (01≤DD≤30, 01≤MM≤12, 2000≤YYYY≤3000).

Гарантируется, что дата сдачи проекта всегда позднее, чем дата выдачи задания на проект.

Выходные данные
Требуется вывести информацию о выполняемых студентами проектах. Строка с записью о каждом проекте должна иметь следующий вид (все поля разделены одним пробелом):

— Название проекта;

— Продолжительность выполнения проекта в днях (даты начала и окончания учитываются);

— Средний балл успеваемости студенческой команды по лабе преподавателя кафедры МОП ЭВМ (среднее арифметическое баллов всех участников команды, которая работает над проектом, вещественное число с точностью 2 знака после запятой. Если проект никто не выполняет, то средний балл считать равным нулю);

— Общее количество студентов всех институтов, которые работают над проектом номер w.

Строки с записями о проектах должны быть отсортированы в лексикографическом порядке по названию проекта.

Примеры
*/


/*A
ЮФУ - современный университет, который активно движется в сторону цифровизации всех сторон своей деятельности. Так, все данные о студентах ЮФУ и их успеваемости хранятся в АСУ вуза.

Данные из АСУ можно скачать только в определенном, заранее известном формате, который преподаватель не может изменить (что-то вроде базы данных в текстовом виде). Но ему необязательно использовать все поля, достаточно выбирать только те из них, которые нужны для решения конкретной задачи.

Следует также иметь в виду, что при вводе данных в АСУ могли быть внесены неточности в написании строковых данных, которые требуется учесть и скорректировать при выводе результата обработки. Т.е. последовательности nsdg, Nsdg, NSDG, nSDG - это одна и та же строка.

Итак, начнем...

Преподаватель кафедры МОП ЭВМ провел лабораторные работы по программированию у всех студентов ЮФУ, за которые студенты могли получить в сумме не более 100 баллов. Все оценки по результатам выполнения лаб он, как и положено, внес в АСУ вуза.

Ректорат ЮФУ решил провести мониторинг успеваемости студентов. От всех преподавателей потребовали списки студентов, набравших не менее К баллов.

Поскольку наш преподаватель, во-первых, ведет занятия в нескольких группах и студентов у него очень много, во-вторых, не любит сам делать то, что за него может сделать машина, то для решения этой задачи он решил решил скачать данные из АСУ вуза и затем их обработать.

Помогите преподавателю написать программу для решения задачи формирования списка студентов, которые набрали не менее K баллов за лабу.

Входные данные
В первой строке на вход подается контрольное количество баллов K (0≤К≤100). Во второй строке на вход подается количество студентов N (0<N≤10000) в АСУ вуза. В следующих N строках даны записи из базы данных АСУ (по одной записи в строке), поля записи разделены одним пробелом:

— Идентификатор института или факультета, за которым закреплен студент (целое число в диапазоне 1..999);

— Фамилия и Имя студента (две последовательности больших и маленьких латинских букв длиной не более 32 символов каждая);

— Количество баллов, набранных студентом по лабам, P (0≤P≤100);

— Название проекта, надо которым работает студент (последовательность больших и маленьких латинских букв и символов подчеркивания длиной не более 255 символов каждая).

Выходные данные
Выведите строки с данными о студентах, у которых количество баллов больше либо равно К.

В каждой строке должны быть указаны следующие поля, разделенные одним пробелом:

— фамилия студента (независимо от того, какими буквами строка фамилия в базе данных, при выводе первая буква должна быть заглавной, а остальные - маленькими);

— имя студента (независимо от того, какими буквами записана строка в базе данных, при выводе первая буква должна быть заглавной, а остальные - маленькими);

— идентификатор института (обязательно три цифры, записанные в круглых скобках);

— количество баллов, набранных студентом по программированию.

Список строк должен быть отсортирован в лексикографическом порядке (по возрастанию фамилии. При равенстве фамилий - по возрастанию имени. Далее - по возрастанию номера института и, наконец, при всех прочих одинаковых полях, по убыванию количества баллов за лабы программированию.
*/