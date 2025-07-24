/*
    * Implement the string reversal function, such as input "hello world", output "dlrow olleh". 
    * a. Use at least 2 ways to implement this function.
    * b. Design a function whose parameters include at least the original string and the output string.
    * 
    */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void RunFirstMethod()
{
    char cInput[] = "hello world";
    char temp; //to store character temporarily
    
    int iHead = 0;
    int iTail = strlen(cInput) - 1; //index purpose
    
    while (iHead < iTail){

        temp = cInput[iHead];
        cInput[iHead] = cInput[iTail]; //store the last character in first current index
        cInput[iTail] = temp; //exchange character
        
        // printf ("Update string : %s \n", str);
        iHead++;
        iTail--;
    }

    printf ("1st method result, updated string : %s \n", cInput);
}

void RunSecondMethod(char* ori_string, char* output_string, int size)
{
    printf ("original string : %s\n", ori_string);
    char* p = ori_string;
    int head = 0;

    printf ("size : %d\n", size);
    while (size != 0){

        printf ("Inserting character to output string : %c\n", *(p+size-1));
        output_string[head] = *(p+size-1);
        printf ("Output string [%d] : %c \n", head, output_string[head]);
        head++;
        size--;
        
    }
    // for (int i = size; i == 0; i--){

    //     printf ("Inserting character to output string : %c\n", *(p+i));
    //     output_string[head] = *(p+i);
    //     printf ("Output string [%d] : %c \n", head, output_string[head]);
    //     head++;
    // }

    // output_string[0] = ori_string[size-1];
    output_string[head] = '\0'; //null terminate the string
}

int main ()
{
    RunFirstMethod();  //First method

    //Second method
    char cInput[] = "hello world";
    int iSize = strlen(cInput);

    char *cOutput = (char*)malloc(iSize * sizeof(char));
    
    if (cOutput == NULL){

        return 0;
    }
    RunSecondMethod(cInput, cOutput, iSize); //using pointer
    printf ("2nd method result, cOutput : %s\n", cOutput);

    free(cOutput); //free allocated memory

    return 0;
    
}