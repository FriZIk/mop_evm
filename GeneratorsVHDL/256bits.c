/*
    VHDL SWITCH-CASE GENERATOR

    Example:
    case v_CONCATENATE is
      when "000" | "100" =>
        r_RESULT <= 0;
      when "001" =>
        r_RESULT <= 1;
      when "010" =>
        r_RESULT <= 2;
      when others =>
        r_RESULT <= 9;
    end case;
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "table.h"

void ToBinary(int temp,FILE *Output,int StopSignal)
{
    int NumberOfDigits = 8;
    int ArrayOfNumbers[NumberOfDigits];

    for(int i = 0;i < NumberOfDigits;i++)
        ArrayOfNumbers[i] = -1;

    int counter = 0;
    while(temp > 0)
    {   
        //printf("%d",temp % 2);
        ArrayOfNumbers[counter] = temp % 2;
        counter++;
        temp = temp / 2;
    }

    for(int j = NumberOfDigits-1;j >= 0;j--)
    {    
        if(ArrayOfNumbers[j] == -1)
        {
            if(j == StopSignal || StopSignal == 8)
            {
                fprintf(Output,"%d",0);
                printf("%d",0);
            }
        }
        else 
        {
            if(j == StopSignal || StopSignal == 8)
            {
                printf("%d",ArrayOfNumbers[j]);
                fprintf(Output,"%d",ArrayOfNumbers[j]);
            }
        }
    }
}

void MainConstructor(FILE *Output)
{
    fprintf(Output,"case v_CONCATENATE is:\n");
    printf("case v_CONCATENATE is:\n");
    // Начинаем
    for(int i = 0;i < 256;i++)
    {
        fprintf(Output,"    when \"");
        ToBinary(i,Output,8);
        for(int j = 0;j < 8;j++)
        {
            if(j == 0)fprintf(Output,"\' => \n       result(%d) <= \'",j);
            else fprintf(Output,"       result(%d) <= \'",j);
            ToBinary(kPi[i],Output,j);
            fprintf(Output,"\';\n");
        }
        printf("\" => \n        result <= \"");
        
    }
    fprintf(Output,"end case;");
}

int main()
{
    printf("сейчас что-то зашаманим с степенями\n");
    int a = 0;

    FILE *Output = fopen("output1.txt","wt");
    MainConstructor(Output);
    fclose(Output);
    return 0;
}