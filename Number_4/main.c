/* 

    4. Read all the contents from a specified binary file and print the file contents to the standard output in the form of continuous hexadecimal strings. 
    You can use the "HxD Hex Editor" tool to generate a simple binary file with a file size of not less than 256 bits.

        a. Save the result in the buffer first and then print it.

        b. Use uppercase letters as printing.

        c. Use lowercase characters as printing.

    @brief : referred to    https://www.geeksforgeeks.org/c/toupper-function-in-c/ and textbook pointer to c

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

#define FILE_NAME  "C:/Users/NP office/Desktop/data.bin" //file to access in the code
#define BUFFER_SIZE 32

int InsertValueIntoBuffer(FILE *file, char *buffer)
{
    int c = 0; //character to store value from file and put into buffer
    int i = 0; //index increment

    while ((c = fgetc(file)) != EOF){

        if (i > BUFFER_SIZE -1){
            
            //0 - 31 iteration
            printf ("Memory full \n");
            return -1;
        }

        *(buffer+i) = c;
        printf ("Inserting bit : %20x \n", c); //printing in hex format
        i++;
    }

    return 0;

}

void PrintMessage(char *msg)
{
    
    for (int i =0; msg[i] != '\0'; i++){

        printf ("%c", toupper(msg[i]));
    }

    printf ("\n");

    for (int i =0; msg[i] != '\0'; i++){

        printf ("%c", tolower(msg[i]));
    }

    printf ("\n");

    return;
}

int main()
{
    int iRet = 0; //return value
    
    char *cBuffer = (char *)calloc(BUFFER_SIZE, sizeof(char)); //256 bits = 32bytes buffer,initialize everything to 0
    if (cBuffer == NULL){

        perror ("Memory allocation failed \n");
        return -1;
    }

    

    FILE *file = fopen(FILE_NAME, "rb"); //read file

    if (file == NULL){

        perror("Error Opening File \n");
        iRet = -1;
        return iRet;
    }


    iRet = InsertValueIntoBuffer(file, cBuffer); //Save value from bin to buffer

    if (iRet != 0){

        char sReturnMsg[] = "Error Inserting value to buffer";
        PrintMessage(sReturnMsg);
    }

    else{

        char sReturnMsg[] = "Operation Success";
        PrintMessage(sReturnMsg);
    }

    iRet = fclose(file);
    if (iRet != 0){

        perror("Error closing file \n");
        return iRet;
    }

    return iRet;
}