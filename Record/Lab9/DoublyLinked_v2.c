#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

typedef struct Node Node;
Node *ptr, *start = NULL, *new1, *curr;

void display()
{
    if(start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    printf("List Contents:\n");
    for(ptr = start; ptr != NULL; ptr = ptr->next)
        printf("%d\n", ptr->data);
}

void insert_beg()
{
    new1 = (Node *) malloc(sizeof(Node));
    printf("Enter Element: ");
    scanf("%d",&new1->data);
    if(start == NULL)
    {
        start = new1;
        new1->next = NULL;
        new1->prev = NULL;
        return;
    }
    new1->prev = NULL;
    new1->next = start;
    start->prev = new1;
    start = new1;
}

void delete_spec()
{
    if(start == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    int el;
    printf("Enter Element: ");
    scanf("%d",&el);
    if(start->data == el)
    {
        ptr = start;
        start = start->next;
        start->prev = NULL;
        free(ptr);
        return;
    }
    for(ptr = start; ptr->next != NULL && ptr->data != el; ptr = ptr->next){}
    if(ptr->data == el && ptr->next == NULL)
    {
        ptr->prev->next = ptr->next;
        free(ptr);
        return;
    }
    if(ptr->data == el)
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        return;
    }
    printf("Element not found\n");
}

void main()
{
    int ch, pos;
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    while(1)
    {
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insert_beg(); break;
            case 2: delete_spec(); break;
            case 3: display(); break;
            default:exit(0);
        }
    }
}

