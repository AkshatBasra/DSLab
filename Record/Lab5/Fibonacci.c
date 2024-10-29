#include <stdio.h>
int fib(int n)
{
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    return fib(n-1) + fib(n-2);
}

void main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    printf("The fibonacci is %d",fib(n));
}
