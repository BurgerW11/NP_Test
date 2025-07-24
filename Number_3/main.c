/*    
*   3. Calculate the size of the file. 
*   a. Use at least 3 ways to implement this function.

    @brief : referred to    https://www.tutorialspoint.com/c_standard_library/c_function_fgetc.htm
                            https://www.geeksforgeeks.org/c/fread-function-in-c/
                            Textbook pointer to c
                            
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

const char *cInputString = "My name is Chong Han Wei. \n";

int WriteFile(const char *filename, const char* string)
{
    int iRet = 0;
    FILE *file = fopen(filename,"w");
    
    if (file == NULL){

        perror("Error Opening File \n");
        iRet = -1;
        return iRet;
    }

    fprintf (file, "%s",string);

    iRet = fclose(file);
    if (iRet != 0){

        perror("Error closing file \n");
        return iRet;
    }

    return iRet;
}
int RunFirstMethod()
{
    
    int iRet = 0;
    
    const char *cFileName = "C:/Users/NP office/Desktop/text.txt";
    
    iRet = WriteFile(cFileName, cInputString);

    if (iRet != 0){

        printf ("First method failed to write file \n");
        return iRet;
    }

    FILE *file = fopen(cFileName, "rb"); //read mode

    if (file == NULL){

        perror("Error Opening File \n");
        int iRet = -1;
        return iRet;
    }

    fseek(file, 0, SEEK_END); //Move pointer 0 distance and move to the end of the file.
    long size = ftell(file); //current position of the pointer in the file. Since each character is a byte, at the end of the file can represent the size of the file.
    
    
    if (iRet != 0){

        perror("Error closing file \n");
        return iRet;
    }

    if (size < 0){

        printf ("First method failed to get size \n");
        return iRet ;
    }

    printf ("Size of %s : %ld bytes \n", cFileName,size);
    printf ("End of 1st method \n");
}

int RunSecondMethod()
{
    const char *cFileName = "C:/Users/NP office/Desktop/text.txt";
    char cBuffer[50];
    int iRet = 0;
    size_t szTotalBt = 0; //total byte that has been read
    size_t szBtRead = 0; // return value for fread(), is the number of bytes that have read succesfully

    iRet = WriteFile(cFileName, cInputString);

    if (iRet != 0){

        printf ("Second method failed to write file \n");
        return iRet;
    }

    FILE *file = fopen(cFileName, "rb");

    if (file == NULL){

        perror("Error Opening File \n");
        iRet = -1;
        return iRet;
    }

    
    bool bFlag = true;

    while ((szBtRead = fread(cBuffer,sizeof(char),sizeof(cBuffer) - 1, file)) > 0){

        szTotalBt += szBtRead;
        printf ("szBtRead : %zu \n", szBtRead);
        printf ("szTotalBt : %zu \n", szTotalBt);
    }
    
    printf ("End of 2nd method \n");
    
}

int RunThirdMethod()
{
    const char *cFileName = "C:/Users/NP office/Desktop/text.txt";
    int c;
    int iSize = 0;
    int iRet = 0;

    iRet = WriteFile(cFileName, cInputString);

    if (iRet != 0){

        printf ("Second method failed to write file \n");
        return iRet;
    }

    FILE *file = fopen(cFileName, "rb");

    if (file == NULL){

        perror("Error Opening File \n");
        iRet = -1;
        return iRet;
    }

    while ((c = fgetc(file)) != EOF){

        printf ("c : %c \n", c);
        iSize++;
    }
    
    printf ("Size of file is : %d \n", iSize);
    printf ("End of method 3 \n");

    iRet = fclose(file);
    if (iRet != 0){

        perror("Error closing file \n");
        return iRet;
    }
    
    return 0;
    
}

int main()
{

    RunFirstMethod(); //using ftell and fseek
    RunSecondMethod(); //using fread
    
    RunThirdMethod();

    return 0;
}