#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};
typedef struct Node Node;

Node *root, *new1, *ptr, *curr;

void create()
{
    char c;
    int item;
    new1 = (Node *) malloc(sizeof(Node));
    printf("Enter element: ");
    scanf("%d", &new1->data);
    new1->left = NULL;
    new1->right = NULL;
    root = new1;
    while(1)
    {
        printf("Add Another Element?(Y/N) ");
        scanf(" %c", &c);
        if(c == 'Y'|| c == 'y')
        {
            new1 = (Node *) malloc(sizeof(Node));
            printf("Enter element: ");
            scanf("%d", &new1->data);
            new1->left = NULL;
            new1->right = NULL;
            curr = root;
            item = new1->data;
            while(curr != NULL)
            {
                ptr = curr;
                curr = (item >= curr->data ?curr->right :curr->left);
            }
            if(item < ptr->data)
                ptr->left = new1;
            else
                ptr->right = new1;
        }
        else
        {
            return;
        }
    }
}

void inorder(Node *temp)
{
    if(temp != NULL)
    {
        inorder(temp->left);
        printf("%d  ", temp->data);
        inorder(temp->right);
    }
}

void preorder(Node *temp)
{
    if(temp != NULL)
    {
        printf("%d  ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(Node *temp)
{
    if(temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d  ", temp->data);
    }
}

int getLevelCount(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int leftMaxLevel = 1 + getLevelCount(node->left);
    int rightMaxLevel = 1 + getLevelCount(node->right);
    if (leftMaxLevel > rightMaxLevel)
    {
        return leftMaxLevel;
    }
    else
    {
        return rightMaxLevel;
    }
}

void printLevel(Node *node, int level)
{
    if (node != NULL && level == 0)
    {
        printf("%s\n", node->data);
    }
    else if (node != NULL)
    {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }
}

void printElements(Node *node)
{
    int i;
    int levelCount = getLevelCount(node);
    for (i = 0; i < levelCount; i++)
    {
        printLevel(node, i);
    }
}

void main()
{
    int ch;
    printf("Create a Binary Tree:\n");
    create();
    printf("Display the Tree:\n");
    printf("1. Pre Order\n2. In Order\n3. Post Order\n4. Level Wise\n5. Exit\n");
    while(1)
    {
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: preorder(root); break;
            case 2: inorder(root); break;
            case 3: postorder(root); break;
            case 4: printElements(root); break;
            default:exit(0);
        }
    }
}
