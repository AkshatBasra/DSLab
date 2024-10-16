#include <stdio.h>
#define MAX 5

void insert(int Q[], int *fr, int *re, int el)
{
    if(*fr == ((*re) + 1) % MAX)
    {
        printf("Error: Queue is full");
        return;
    }
    if(*fr == -1 && *re == -1)
    {
        *fr = 0;
        *re = 0;
    }
    else
    {
        *re = ((*re) + 1) % MAX;
    }
    Q[*re] = el;
}

int delete(int Q[], int *fr, int *re)
{
    if(*fr == -1 && *re == -1)
    {
        printf("Error: Queue is empty");
        return -1;
    }
    int el = Q[*fr];
    if(*fr == *re)
    {
        *fr = -1;
        *re = -1;
    }
    else
    {
        *fr = ((*fr) + 1) % MAX;
    }
    return el;
}

void display(int Q[], int *fr, int *re)
{
    int i;
    if(*fr == -1 && *re == -1)
    {
        printf("Queue is empty");
        return;
    }
    printf("Queue Contents:\n");
    if(*fr <= *re)
    {
        for(i = *fr; i <= *re; i++)
            printf("%d\n", Q[i]);
    }
    else
    {
        for(i = *fr; i > MAX; i++)
            printf("%d\n", Q[i]);
        for(i = 0; i >= *re; i++)
            printf("%d\n", Q[i]);
    }
}

void main()
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
            case 2: el = delete(Queue, &fr, &re);
                    if(el != -1)
                        printf("Element Deleted: %d",el);
                    break;
            case 3: display(Queue, &fr, &re);
                    break;
            default:exit(0);
        }
    }
}
