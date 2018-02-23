/** 
*   Name: Pavan Kumar Kamra
*   Course: BTP500
*   Purpose: Lab#1 -- Factorial, Power, and Fibonacci functions
**/

//factorial function is calculated by multiplying every number between 1 and n
unsigned int factorial (unsigned int n)
{
   unsigned int num = 1; 
   
   for (unsigned int i = n; i > 0; i--)
   {
       num = num * i; 
   }

   return num;
}

//power function returns base^n 
double power (double base, unsigned int n)
{
   double b = 1; 
   double baseNum = base; 
   unsigned int exponent = n; 

   for (int i=0; i<exponent; i++)
   {
       b = b * baseNum;
   } 

   return b; 
}

//a function that outputs the fibonacci sequence.
unsigned int fibonacci (unsigned int n)
{
     unsigned int f0 = 0; 
     unsigned int f1 = 1; 
     unsigned int fibNum = 0;
     
     if (n == 0)  
        return f0;   
     else if (n == 1)
        return f1;
     else
     {
          for (int i=1; i<n; i++)
          {
               fibNum = f0 + f1; 
               f0 = f1; 
               f1 = fibNum;
          }
     }
     return fibNum;	
}
