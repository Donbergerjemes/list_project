#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to add odd numbers to the beginning and even numbers to the end
void addNumbers()
{
    int num;
    while (1)
    {
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &num);

        if (num == -1)
        {
            break;
        }

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = NULL;

        if (num % 2 == 1)
        { // Odd number, add to the beginning
            if (head == NULL)
            {
                head = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }
        else
        { // Even number, add to the end
            if (head == NULL)
            {
                head = newNode;
            }
            else
            {
                struct Node *current = head;
                while (current->next != NULL)
                {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
    }
}

// Function to generate and add 100 random numbers to the list
void addRandomNumbers()
{
    for (int i = 0; i < 100; i++)
    {
        int randomNum = rand() % 100 + 1; // Generate a random number between 1 and 100
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = randomNum;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

// Function to sort the list in descending order
void sortDescending()
{
    if (head == NULL)
    {
        return;
    }

    struct Node *sortedList = NULL;
    while (head != NULL)
    {
        struct Node *current = head;
        head = head->next;

        if (sortedList == NULL || current->data >= sortedList->data)
        {
            current->next = sortedList;
            sortedList = current;
        }
        else
        {
            struct Node *temp = sortedList;
            while (temp->next != NULL && current->data < temp->next->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    head = sortedList;
}

// Function to display the linked list
void displayList()
{
    struct Node *current = head;
    printf("List: ");
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to count and display student information
void countAndDisplayStudents()
{
    struct Node *current = head;
    int count = 0;

    while (current != NULL)
    {
        printf("%d- Student: %s %d %d\n", count + 1, current->data, current->data, current->data);
        current = current->next;
        count++;
    }

    printf("Total number of students: %d\n", count);
}

// Function to search records by student number in the list
void searchRecordByNumber(int target)
{
    struct Node *current = head;

    while (current != NULL)
    {
        if (current->data == target)
        {
            printf("Student with student number %d found.\n", target);
            return;
        }
        current = current->next;
    }

    printf("Student with student number %d not found.\n", target);
}

// Function to delete the next node from the node with the searched student number
void deleteNextNode(int target)
{
    struct Node *current = head;

    while (current != NULL)
    {
        if (current->data == target && current->next != NULL)
        {
            struct Node *temp = current->next;
            current->next = temp->next;
            free(temp);
            printf("Deleted the next node from the student with student number %d.\n", target);
            return;
        }
        current = current->next;
    }

    printf("No student with student number %d found or no next node to delete.\n", target);
}

// Function to find the record with the longest name
void findLongestName()
{
    struct Node *current = head;
    int maxLength = 0;
    int longestName = 0;

    while (current != NULL)
    {
        if (current->data > maxLength)
        {
            maxLength = current->data;
            longestName = current->data;
        }
        current = current->next;
    }

    if (maxLength > 0)
    {
        printf("The longest name in the list: %d\n", longestName);
        printf("Length: %d\n", maxLength);
    }
    else
    {
        printf("No student records found.\n");
    }
}

// Function to free the memory of the linked list
void freeList()
{
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add numbers (odd to beginning, even to end)\n");
        printf("2. Add 100 random numbers\n");
        printf("3. Sort numbers in descending order\n");
        printf("4. Display the list\n");
        printf("5. Count and display student information\n");
        printf("6. Search by student number\n");
        printf("7. Delete next node by student number\n");
        printf("8. Find the record with the longest name\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addNumbers();
            break;
        case 2:
            addRandomNumbers();
            break;
        case 3:
            sortDescending();
            break;
        case 4:
            displayList();
            break;
        case 5:
            countAndDisplayStudents();
            break;
        case 6:
            int target;
            printf("Enter a student number to search: ");
            scanf("%d", &target);
            searchRecordByNumber(target);
            break;
        case 7:
            printf("Enter a student number to delete its next node: ");
            scanf("%d", &target);
            deleteNextNode(target);
            break;
        case 8:
            findLongestName();
            break;
        case 9:
            freeList();
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
