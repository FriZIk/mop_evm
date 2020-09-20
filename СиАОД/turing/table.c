#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Command
{
    char NewSymbol; // Какой символ ставится в текущую ячейку
    char Displacement;  // В какую сторону сместиться 
    int NewState; // В какое состояние переходи машина
};
typedef struct Command Command;

Command** GetCommands(int *CntOfLines,int *CntOfColums)
{
    FILE *CommandsFile = fopen("commands_copy.txt","rt");
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
            printf("%-5s ",str);
            
            cmd[i][j].NewSymbol = str[0];
            cmd[i][j].Displacement = str[1];
            if(strlen(str) - 2 == 1)cmd[i][j].NewState = str[2] - 48; 
            else if(strlen(str) - 2 == 2)cmd[i][j].NewState = (str[2]-48)*10 + (str[3]-48);
        }
        printf("\n");
    }
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
    *CntOfLines = CountOfLines;
    *CntOfColums = CountOfColums;
    return cmd;
}

int main()
{
    int CountOfLines,CountOfColums;
    Command **ComTable = GetCommands(&CountOfLines,&CountOfColums);
    printf("\n");
    printf("%d %d\n",CountOfLines,CountOfColums);
    for(int i = 0;i < CountOfLines;i++)
    {
        for(int j = 1;j <= CountOfColums;j++)
        {
            if(ComTable[i][j].NewSymbol == '0') printf("       ");
            else printf("%c%c%d    ",ComTable[i][j].NewSymbol,ComTable[i][j].Displacement,ComTable[i][j].NewState);
        }
        printf("\n");
    }
    return 0;
}