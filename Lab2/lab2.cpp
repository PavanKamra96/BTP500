/**
* Name: Pavan Kumar Kamra
* Date: 9/22/2017
* Course: BTP500
* Purpose: This lab is to enhance our skills on recursive functions.
**/

unsigned int factorial (unsigned int n)
{
      if (n==0 || n==1)
          return 1; 
      else 
          return n * factorial(n-1);
}

double power (double base, unsigned int n){
    double powerAmt = 0;
    if (n == 0)
        return 1; 
    else if (n==1)
        return base; 
    else
        return  base * power(base, n-1);
}

unsigned int fibonacci (unsigned int n){
    if (n==0 || n==1)
       return n; 
    else
       return fibonacci(n-2) + fibonacci(n-1);
}
