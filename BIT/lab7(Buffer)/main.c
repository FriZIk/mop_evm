#include <stdio.h>
#include <string.h>

int main(void)
{

    buff_overflow_test();
    return 0;
}


int buff_overflow_test()
{

    char buff_var2[6];
    int pass = 0;

    printf("\n Enter the password : \n");
    gets(buff_var0);

    if(strcmp(buff_var0, "pass2"))
    {
        printf ("\n Wrong Password \n");
    }
    else
    {
        printf ("\n Correct Password \n");
        pass = 1;
    }

    if(pass)
    {
       /* Now Give root or admin rights to user*/
        printf ("\n Root privileges given to the user \n");
    }
}
