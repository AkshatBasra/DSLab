#include <stdio.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node Node;
Node *ptr, *start = NULL, *new1, *curr;

void create()
{
    int c = 1;
    while(c == 1)
    {
        new1 = (Node *) malloc(sizeof(Node));
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

void display()
{
    if(start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    printf("List Contents:\n");
    for(ptr = start; ptr != NULL; ptr = ptr->link)
        printf("%d", ptr->data);
}

void main()
{
    int ch;
    printf("1. Create\n2. Display\n3. Exit\n");
    while(1)
    {
        printf("Enter Choice: ");
        scanf("%d\n", &ch);
        switch(ch)
        {
            case 1: create();
                    break;
            case 2: display();
                    break;
            default:exit(0);
        }
    }
}

