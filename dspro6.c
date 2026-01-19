#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

char cq[SIZE];
int front = -1, rear = -1;

/* Insert operation */
void CQ_insert()
{
    char ele;

    if (front == (rear + 1) % SIZE)
    {
        printf("Queue is full\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf(" %c", &ele);   // space before %c is IMPORTANT

    if (front == -1)   // first insertion
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    cq[rear] = ele;
}

/* Delete operation */
void CQ_delete()
{
    char item;

    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    item = cq[front];
    printf("Deleted element is: %c\n", item);

    if (front == rear)   // only one element
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

/* Display operation */
void CQ_display()
{
    int i;

    if (front == -1)
    {
        printf("Circular queue is empty\n");
        return;
    }
    else{

    printf("Elements in circular queue:\n");
    for(i=front;i!=rear;i=(i+1)%SIZE){
        printf(" %c\t",cq[i]);
    }
    printf(" %c\n",cq[i]);
}
}

    

int main()
{
    int ch;

    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            CQ_insert();
            break;

        case 2:
            CQ_delete();
            break;

        case 3:
            CQ_display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
