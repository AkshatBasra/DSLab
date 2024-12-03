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

void create()
{
    char c;
    new1 = (Node *) malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &new1->data);
    new1->prev = NULL;
    start = new1;
    curr = new1;
    while(1)
    {
        printf("Create another element?(Y/N) ");
        scanf(" %c",&c);
        if(c == 'y'|| c == 'Y')
        {
            new1 = (Node *) malloc(sizeof(Node));
            printf("Enter data: ");
            scanf("%d", &new1->data);
            new1->prev = curr;
            curr->next = new1;
            curr = new1;
        }
        else
        {
            curr->next = NULL;
            return;
        }
    }
}

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

void insert_end()
{
    new1 = (Node *) malloc(sizeof(Node));
    printf("Enter Element: ");
    scanf("%d",&new1->data);
    if(start == NULL)
    {
        new1->prev = NULL;
        start = new1;
        new1->next = NULL;
        return;
    }
    ptr = start;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new1->prev = ptr;
    ptr->next = new1;
    new1->next = NULL;
}

void insert_pos(int pos)
{
    new1 = (Node *) malloc(sizeof(Node));
    printf("Enter Element: ");
    scanf("%d",&new1->data);
    if(pos == 1)
    {
        new1->next = start;
        start->prev = new1;
        new1->prev = NULL;
        start = new1;
        return;
    }
    int i = 1;
    for(ptr = start; ptr != NULL || i < pos - 1; ptr = ptr->next)
    {
        i++;
    }
    if(i == pos-1)
    {
        new1->next = ptr->next;
        ptr->next->prev = new1;
        new1->prev = ptr;
        ptr->next = new1;
    }
    if(ptr == NULL)
    {
        printf("Entered position is greater than number of elements\n");
    }
}

void delete_beg()
{
    if(start == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    ptr = start;
    start = start->next;
    start->prev = NULL;
    free(ptr);
}

void delete_end()
{
    if(start == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    for(ptr = start; ptr->next != NULL; ptr = ptr->next){}
    ptr->prev->next = NULL;
    free(ptr);
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
    int ch, ch1, pos;
    printf("1. Create\n2. Insert\n3. Delete\n4. Display\n5. Exit\n");
    while(1)
    {
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: create();
                    break;
            case 2: printf("1. Beginning\n2. End\n3. At position\n");
                    scanf("%d", &ch1);
                    switch(ch1)
                    {
                        case 1: insert_beg();
                                break;
                        case 2: insert_end();
                                break;
                        case 3: printf("Enter Position: ");
                                scanf("%d", &pos);
                                insert_pos(pos);
                                break;

                    }
                    break;
            case 3: printf("1. Beginning\n2. End\n3. At position\n");
                    scanf("%d", &ch1);
                    switch(ch1)
                    {
                        case 1: delete_beg();
                                break;
                        case 2: delete_end();
                                break;
                        case 3: delete_spec();
                                break;

                    }
                    break;
            case 4: display();
                    break;
            default:exit(0);
        }
    }
}
