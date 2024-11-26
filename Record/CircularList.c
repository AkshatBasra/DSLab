#include <stdio.h>
#include <stdlib.h>

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
    curr->link = start;
}

void display()
{
    if(start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    printf("List Contents:\n");
    for(ptr = start; ptr->link != start; ptr = ptr->link)
        printf("%d\n", ptr->data);
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
        new1->link = start;
        return;
    }
    for(ptr = start; ptr->link != start; ptr = ptr->link){}
    ptr->link = new1;
    new1->link = start;
    start = new1;
}

void insert_end()
{
    new1 = (Node *) malloc(sizeof(Node));
    printf("Enter Element: ");
    scanf("%d",&new1->data);
    if(start == NULL)
    {
        start = new1;
        new1->link = start;
        return;
    }
    for(ptr = start; ptr->link != start; ptr = ptr->link){}
    ptr->link = new1;
    new1->link = start;
}

void insert_pos(int pos)
{
    new1 = (Node *) malloc(sizeof(Node));
    printf("Enter Element: ");
    scanf("%d",&new1->data);
    if(start == NULL && pos != 1)
    {
        printf("Entered position is greater than number of elements\n");
        return;
    }
    if(pos == 1)
    {
        new1->link = start;
        for(ptr = start; ptr->link != start; ptr = ptr->link){}
        ptr->link = new1;
        start = new1;
        return;
    }
    int i;ptr = start->link;
    for(i = 1; ptr != start && i < pos - 1; ptr = ptr->link)
    {
        i++;
    }
    if(ptr ==start)
    {
        printf("Entered position is greater than number of elements\n");
        return;
    }
    new1->link = ptr->link;
    ptr->link = new1;
}

void delete_beg()
{
    if(start == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    if(start->link == start)
    {
        free(start);
        start = NULL;
        return;
    }
    for(ptr = start; ptr->link != start; ptr = ptr->link){}
    ptr->link = start->link;
    free(start);
    start = ptr->link;
}

void delete_end()
{
    if(start == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    if(start->link == start)
    {
        free(start);
        return;
    }
    for(ptr = start; ptr->link->link != start; ptr = ptr->link){}
    free(ptr->link);
    ptr->link = start;
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
    if (start->data == el)
    {
        if(start->link == start)
        {
            free(start);
            return;
        }
        for(ptr = start; ptr->link->link != start; ptr = ptr->link){}
        ptr->link = start->link;
        free(start);
        start = ptr->link;
        return;
    }
    Node* ptr2;
    ptr = start;
    while(ptr->link != start && ptr->data != el)
    {
        ptr2 = ptr;
        ptr = ptr->link;
    }
    if(ptr->data == el)
    {
        ptr2->link = ptr->link;
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
            case 3: printf("1. Beginning\n2. End\n3. Specific Element\n");
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
