# include <stdio.h>
#define MAX 4

int queue[5], fr = -1, re = -1;

void insert(int el);
int deleted();
void display();
void queueImplementation();

void main()
{
    queueImplementation();
}

void queueImplementation()
{
    int c;
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
                    insert(el);
                    break;
            case 2: el = deleted();
                    if(el != -1)
                        printf("Element Deleted: %d",el);
                    break;
            case 3: display();
                    break;
            default:exit(0);
        }
    }
}

void insert(int el)
{
    if(re == MAX - 1)
    {
        printf("Error: Queue is full");
        return;
    }
    if(re == -1)
    {
        re = 0;
        fr = 0;
    }
    queue[re] = el;
    re++;
}

int deleted()
{
    if(fr == -1 && re == -1)
    {
        printf("Queue is empty");
        return -1;
    }
    int el = queue[fr++];
    if(fr == re)
    {
        fr = -1;
        re = -1;
    }
    return el;
}

void display()
{
    if(fr == -1)
    {
        printf("Queue is empty");
        return;
    }
    printf("Contents:\n");
    for(int i = fr; i < re; i++)
        printf("%d\n",queue[i]);
}
