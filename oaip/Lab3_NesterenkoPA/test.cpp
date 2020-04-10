#include <iostream>
#include <string.h>

using namespace std;

int main()// Циклический сдвиг на один разряд вправо
{
    char str[11];
    fgets(str,11,stdin);
    printf("%s\n",str);
    int len = strlen(str);
    return 0;
}