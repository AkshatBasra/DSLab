#include <stdio.h>
#define MAX 4

void insert(int Q[], int *fr, int *re, int el)
{
    if(*re == MAX - 1)
    {
        printf("Error: Queue is full");
        return;
    }
    if(*re == -1)
    {
        *re = 0;
        *fr = 0;
    }
    Q[(*re)++] = el;
}

int deleted(int Q[], int *fr, int *re)
{
    if(*fr == -1 && *re == -1)
    {
        printf("Queue is empty");
        return -1;
    }
    int el = Q[(*fr)++];
    if(*fr == *re)
    {
        *fr = -1;
        *re = -1;
    }
    return el;
}

void display(int Q[], int *fr, int *re)
{
    if(*fr == -1)
    {
        printf("Queue is empty");
        return;
    }
    printf("Contents:\n");
    for(int i = *fr; i < *re; i++)
        printf("%d\n",Q[i]);
}

void queueImplementation()
{
    int c, Queue[5], fr = -1, re = -1;
    int el;
    printf("1. Insert to Queue\n2. Delete from Queue\n3. Display Queue\n4. Exit\n");
    while(1)
    {
        printf("\n\nEnter Choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("Enter Element: ");
                    scanf("%d",&el);
                    insert(Queue, &fr, &re, el);
                    break;
            case 2: el = deleted(Queue, &fr, &re);
                    if(el != -1)
                        printf("Element Deleted: %d",el);
                    break;
            case 3: display(Queue, &fr, &re);
                    break;
            default:exit(0);
        }
    }
}

void main()
{
    queueImplementation();
}
