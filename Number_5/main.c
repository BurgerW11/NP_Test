/* 
    5. The string "Embedded, Linux, Software, Engineer, 2025, 06, 02", uses "," in the string as a delimiter, prints each separated string, 
    and if the string can be converted into an integer, prints it as an integer data.

    a. The result is first saved in the buffer and then printed.

    b. Use at least 2 ways to implement this function.

    @brief : referred to   https://www.geeksforgeeks.org/cpp/strtok-strtok_r-functions-c-examples/ 
                           https://cplusplus.com/reference/cstdlib/strtol/
                           https://www.geeksforgeeks.org/cpp/strtok-strtok_r-functions-c-examples/
                           https://www.w3schools.com/c/ref_string_strchr.php
                           https://www.w3schools.com/c/ref_string_strcat.php
                           textbook pointer to C
      
   
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void StoreIntoBuffer(char *buffer, char *ptr, int *index)
{
   int i = 0;

   while(1){

      buffer[(*index)] = *(ptr+i);
      (*index)++;
      // printf ("index value : %d\n", *index);
      // printf ("store character : %c\n", *(ptr+i));
      i++;   
      if(*(ptr+i) == '\0'){
         //do not insert '\0' in the string yet
         break;
      }
              
   }
}

bool AssertInteger(long val)
{
   if (val != 0){
      return true;
   }

   return false;
}

void RunFirstMethod()
{
   char sString[] = "Embedded, Linux, Software, Engineer, 2025, 06, 02" ; //string declaration, should not use const because strtok needs to modify the string
   char delim[] = ",";
   char cBuffer[100] = {0};
   long int lRet = 0;
   char *pEnd = NULL;
   int   index = 0; //to get the index of the last message stored in the array ( the size of the buffer that is filled with characters)
   bool bRet = false;

   char *ptr = strtok(sString,delim);

      while (ptr != NULL){

      /*
      *   Print message first before moving to next strtok, 
      *   This is to make sure it can print the first token, and also prevent undefined behaviour when printing NULL in the end
      */
      printf ("token captured : %s \n", ptr); //print each separated string
      
      lRet = strtol(ptr, &pEnd,10);// using strtol instead of atoi because is safer as it can distinguish difference between return value 0 and invalid 0, arg[3] is 10 to represent base10

      bRet = AssertInteger(lRet);

      if (bRet){
            
         //if iRet is not 0, then it is an integer
         printf ("This is an integer value : %d \n", lRet); // print as integer
      }

      else{

         printf ("This is not an integer value : %s \n", ptr); // print as integer
      }
        
      StoreIntoBuffer(cBuffer, ptr, &index); 
      
      ptr = strtok(NULL, delim); //use NULL to tell the ptr to proceed with where it left off, passing sString again will cause infinite loop
      
   }

   cBuffer[index] = '\0'; //insert null terminator
   char *pFinalRes = cBuffer;
   printf ("Final result : %s \n", pFinalRes);
   printf ("End of 1st method\n");
}

void RunSecondMethod()
{
   char sString[] = "Embedded, Linux, Software, Engineer, 2025, 06, 02" ;  //Given string
   char *pStart = sString; //this pointer will be pointing to the beginning of the string first
   char *pRes = NULL; // this pointer be moving around the string
   // int iSize = sizeof(sString)/sizeof(sString[0]); //get the total bytes in sString[];
   char cTempBuffer[50] = {0};
   char cFinalBuffer[100] = {};
   size_t len = 0;
   long lRet = 0;
   char *pEnd = NULL;
   bool bRet = false;
   
   while ((pRes = strchr(pStart,',')) != NULL){

      len = pRes - pStart; //size of the string before ',' is found
      strncpy(cTempBuffer, pStart, len); //copy data from sString to cBuffer, size of data based on length
      cTempBuffer[len] = '\0'; //insert null terminator
      printf ("token string : %s \n", cTempBuffer);
      lRet = strtol(cTempBuffer, &pEnd,10);
      bRet = AssertInteger(lRet); //check if it is integer

      if (bRet){

         printf ("This is an integer : %d \n", lRet); //print integer
      }

      else{

         printf ("This is not an integer : %s \n", cTempBuffer);
      }

      pStart = pRes + 1; //start next to where it has left earlier on

      strcat(cFinalBuffer, cTempBuffer);
   }
   printf ("Final result : %s \n", cFinalBuffer);
   printf ("End of 2nd method\n");

}

 int main()
 {

    RunFirstMethod(); //using strtok
    RunSecondMethod(); //using strchr, manually select token
    
    
    return 0;
 }   