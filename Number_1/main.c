#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
*   1. Insert the string "Linux" into the string "Embedded Software Engineer", 
*   and the result is "Embedded Linux Software Engineer".
*
*   a. The result is first saved in the buffer and then printed.
*
*   b. Use at least 3 ways to implement string insertion.
*   c. Design a function whose parameters include at least the original string, the string to be inserted, and the output string.
*/

const char *cEmbedSE = "Embedded Software Engineer";
const char *cInput =  "Linux";

void RunFirstMethod()
{
    const char *cSpace = " ";
    char cOutput[100] = "";

    /*First method : Using memmove()*/
    memmove(cOutput,cEmbedSE,9); //Put "Embedded" into output buffer first, 9 includes the space
    memmove(cOutput + 9,cInput,strlen(cInput)); // Insert "Linux" in the buffer after "Embedded "
    memmove(cOutput + 9 + strlen(cInput),cSpace, 1);
    memmove(cOutput + 9 + strlen(cInput) + strlen(cSpace), cEmbedSE + 9, strlen(cEmbedSE+9) +1);
    printf ("First method using memmove, cOutput[] : %s\n", cOutput);    
}

void RunSecondMethod()
{
    char cOutput[100] = "";
    //Second method :  using sprintf()
    int i =0;
    while (cEmbedSE[i] != '\0' && cEmbedSE[i] != ' '){
        i++; //Now we know which position to add our new string
    }

    i++;//this is for spacing
    strlen(cInput);
    char prefix[50];
    char suffix[50];
    char *cSpacing = " ";
        
    strncpy(prefix, cEmbedSE, i); //copy "Embedded" into prefix. Bytes to copy refers to i
    prefix[i] = '\0'; //spacing
    strcpy(suffix, &cEmbedSE[i]); //copy remaining of cEmbedSE starting from location byte i
    snprintf (cOutput, sizeof(cOutput), "%s%s%s%s",prefix, cInput,cSpacing, suffix);
    printf("Second method using snprintf, cOutput[] : %s\n", cOutput);
}

void RunThirdMethod(const char *ori_string, const char *insert_string, char *res)
{
    /* Manual copy using loop */
    int i = 0; //increment index that refer to ori_string[]
    int j = 0; //increment index that refer to res[]
    int k = 0; //increment index that refer to insert_string

    //First copy embedded into result
    while (ori_string[i] != ' '){
        
        res[j++] = ori_string[i++]; //use the current value, increment is made at the end
    }

    res[j++] = ori_string[i++]; // copy the space

    //copy "linux"
    while(insert_string[k] != '\0'){

        res[j++] = insert_string[k++];
    }
    res[j++] = ' '; //spacing

    //copy remaining
    while(ori_string[i] != '\0'){
        
        res[j++] = ori_string[i++];
    }

    //ends with null terminator
    res[j] = '\0';

    printf ("Third method result using manual copy, res[] : %s\n", res);
}

int main (void)
{
     /*The result is first saved in the buffer and then printed. */
    char cEndResult[] = "Embedded Linux Software Engineer";
    // char *cOutputRes = " "; // This cannot be used as this is pointer to a string literal, is only a read-only memory
    char cOutputRes[100];
    
    RunFirstMethod();
    RunSecondMethod();
    RunThirdMethod(cEmbedSE, cInput, cOutputRes); //param to include : original string, string to insert, output string
    
    printf ("Passed in pointer to character, cOutputRes[] : %s\n", cOutputRes);
    
    return 0;
}