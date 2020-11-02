#include <stdio.h>
#include <ctype.h>


enum COLOR {BLUE = 9, GREEN, TURQUOISE, RED, VIOLET, YELLOW};

void textcolor(int x, int y, WORD color)
{
    HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD  coord  = {x, y};
    WriteConsoleOutputAttribute(stdOut, &color , 1, coord, NULL);
}

int main()
{
    char* str = "<<< Happy new year 2008! >>>";
    printf("Result:\n%s\n", str);
    for(int i = 0; str[i]; i++)
        if(!isalpha(str[i]))
           textcolor(i, 1, RED);
    return 0;
}
