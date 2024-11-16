#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;

node *ptr, *start1 = NULL, *start2 = NULL, *start = NULL, *new1;

void concatenate()
{
    if(start1 == NULL && start2 == NULL)
    {
        printf("Linked Lists are empty\n");
        return;
    }
    if(start1 == NULL)
    {
        start = start2;
        return;
    }
    if(start2 == NULL)
    {
        start = start1;
        return;
    }
    ptr = start1;
    for(ptr = start1; ptr->link != NULL; ptr = ptr->link){}
    ptr->link = start2;
    start = start1;
    start1 = start2 = NULL;
}

void reverse()
{
    node *a = start, *b = NULL, *c = NULL;
    while(a != NULL)
    {
        c = b;
        b = a;
        a = a->link;
        b->link = c;
    }
    start = b;
}

node *curr;

void createA()
{
    int c = 1;
    while(c == 1)
    {
        new1 = (node *) malloc(sizeof(node));
        printf("Enter data: ");
        scanf("%d", &new1->data);
        if(start == NULL)
        {
            start = new1;
            curr = new1;
        }
        else
        {
            curr->link = new1;
            curr = new1;
        }
        printf("Create another element?(1: Yes) ");
        scanf("%d",&c);
    }
    curr->link = NULL;
}

void display(node *startTemp)
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
    printf("Create List 1:\n");
    createA();
    start1 = start;
    start = NULL;
    printf("\n\nCreate List 2:\n");
    createA();
    start2 = start;
    start = NULL;
    concatenate();
    printf("Concatenating Lists\n");
    display(start);
    printf("Reversing the list\n");
    reverse();
    display(start);
}
