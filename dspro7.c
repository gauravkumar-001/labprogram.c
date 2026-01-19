#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure definition */
struct student
{
    char usn[20];
    char name[20];
    char branch[10];
    int sem;
    char phno[15];
    struct student *next;
};

struct student *head = NULL;

/* Create node */
struct student* createNode()
{
    struct student *newNode;
    newNode = (struct student*)malloc(sizeof(struct student));

    printf("Enter USN: ");
    scanf("%s", newNode->usn);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Branch: ");
    scanf("%s", newNode->branch);
    printf("Enter Semester: ");
    scanf("%d", &newNode->sem);
    printf("Enter Phone No: ");
    scanf("%s", newNode->phno);

    newNode->next = NULL;
    return newNode;
}

/* Insert at front */
void insertFront()
{
    struct student *newNode = createNode();
    newNode->next = head;
    head = newNode;
}

/* Insert at end */
void insertEnd()
{
    struct student *newNode = createNode();
    struct student *temp;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/* Delete from front */
void deleteFront()
{
    struct student *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from front\n");
}

/* Delete from end */
void deleteEnd()
{
    struct student *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Node deleted from end\n");
}

/* Display and count */

void display()
{
    struct student *temp;
    int count = 0;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("\nStudent Details:\n");

    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf("%s %s %s %d %s\n",
               temp->usn,
               temp->name,
               temp->branch,
               temp->sem,
               temp->phno);
        count++;
    }

    printf("Total nodes = %d\n", count);
}
 
/* Main menu */
int main()
{
    int choice, n, i;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Create SLL (Front Insertion)\n");
        printf("2. Display and Count\n");
        printf("3. Insert at End\n");
        printf("4. Delete from End\n");
        printf("5. Insert at Front\n");
        printf("6. Delete from Front\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of students: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                insertFront();
            break;

        case 2:
            display();
            break;

        case 3:
            insertEnd();
            break;

        case 4:
            deleteEnd();
            break;

        case 5:
            insertFront();
            break;

        case 6:
            deleteFront();
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}