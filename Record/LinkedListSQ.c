#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node Node;

Node *ptr, *stack = NULL, *queue = NULL, *start = NULL, *new1, *re = NULL;

void push()
{
    new1 = (Node *) malloc(sizeof(Node));
    printf("Enter Element: ");
    scanf("%d",&new1->data);
    if(stack == NULL)
    {
        stack = new1;
        new1->link = NULL;
        return;
    }
    new1->link = stack;
    stack = new1;
}

void pop()
{
    if(stack == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    ptr = stack;
    stack = stack->link;
    free(ptr);
}

void insert()
{
    new1 = (Node *) malloc(sizeof(Node));
    printf("Enter Element: ");
    scanf("%d",&new1->data);
    if(re == NULL)
    {
        re = new1;
        new1->link = NULL;
        queue = re;
        return;
    }
    re->link = new1;
    re = new1;
    new1->link = NULL;
}

void delete()
{
    if(queue == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    ptr = queue;
    queue = queue->link;
    free(ptr);
}

void display(Node *startTemp)
{
    if(startTemp == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    printf("List Contents:\n");
    for(ptr = startTemp; ptr != NULL; ptr = ptr->link)
        printf("%d\n", ptr->data);
}

void main()
{
    int c;
    printf("1. Stack\n2. Queue\n");
    scanf("%d", &c);
    if(c == 1)
    {
        int c2;
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        while(1)
        {
            printf("Enter Choice: ");
            scanf("%d", &c2);
            switch(c2)
            {
                case 1: push();
                        break;
                case 2: pop();
                        break;
                case 3: display(stack);
                        break;
                default:exit(0);
            }
        }
    }
    else
    {
        int c2;
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        while(1)
        {
            printf("Enter Choice: ");
            scanf("%d", &c2);
            switch(c2)
            {
                case 1: insert();
                        break;
                case 2: delete();
                        break;
                case 3: display(queue);
                        break;
                default:exit(0);
            }
        }
    }
}
