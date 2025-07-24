/* 
    6. Use the function pointer (callback function) mechanism to implement a simple calculator that supports addition, subtraction, multiplication and division.

    a. Function interface: int calculate(int a, int b, operation_func op);

    b. Function pointer type definition: typedef int (*operation_func)(int, int);

    c. Design 4 callback functions: addition, subtraction, multiplication and division.

    @brief  Referred to :   https://medium.com/@kasra_mp/implementing-callback-functions-using-function-pointers-in-c-3e12838ef222

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*operation_func)(int,int);


int AddNumbers(int a, int b)
{
    return (a + b);
}

int SubtractAFromB(int a, int b)
{
    return (a - b);
}

int MultiplyNumbers(int a, int b)
{
    return (a * b);
}

int DivideAfromB (int a, int b)
{
    return (a / b);
}

int Calculate(int a , int b, operation_func func)
{
    int iRet = 0;

    if (func == AddNumbers){

        iRet = AddNumbers(a,b);
    }

    else if(func == SubtractAFromB){

        iRet = SubtractAFromB(a,b);
    }

    else if(func == MultiplyNumbers){

        iRet = MultiplyNumbers(a,b);
    }

    else{
         iRet = DivideAfromB (a,b);
    }

    return iRet;
}

int main()
{
    operation_func maths_operation;
    maths_operation = AddNumbers;
    maths_operation = SubtractAFromB;
    maths_operation = MultiplyNumbers;
    maths_operation = DivideAfromB;

    int a = 100;
    int b = 10;
    int iRet = 0;

    iRet = Calculate(a,b,AddNumbers);
    printf("Add A and B : %d\n", iRet);

    iRet = Calculate(a,b,SubtractAFromB);
    printf ("Subract A from B : %d \n", iRet);

    iRet = Calculate(a,b,MultiplyNumbers);
    printf ("Multiply A and B : %d \n", iRet);

    iRet = Calculate(a,b,DivideAfromB);
    printf ("Divide A from B : %d \n", iRet);
    
    
    return 0;

}