#include <stdio.h>
void ToH(int n, char S, char T, char D)
{
    if(n == 1)
        printf("Move %d from %c to %c\n",n, S, D);
    else
    {
        ToH(n-1, S, D, T);
        printf("Move %d from %c to %c\n",n, S, D);
        ToH(n-1, T, S, D);
    }
}

void main()
{
    int n;
    char S = 'S', T = 'T', D = 'D';
    printf("Enter number: ");
    scanf("%d",&n);
    ToH(n, S, T, D);
}
