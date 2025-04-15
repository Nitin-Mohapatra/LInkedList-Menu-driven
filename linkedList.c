#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct node {
    int value;
    struct node *next;
};

struct node *head = NULL, *temp = NULL, *cur = NULL;

// Function to print the linked list
void iterator() {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Insert at first
void insertAtFirst() {
    int val;
    printf("Enter the value to insert at first: ");
    scanf("%d", &val);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = val;
    newNode->next = head;
    head = newNode;
    iterator();
}

// Insert at last
void insertAtLast() {
    int val;
    printf("Enter the value to insert at last: ");
    scanf("%d", &val);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    iterator();
}

// Insert in between
void insertInBetween(int pos) {
    int val;
    printf("Enter the value to insert at position %d: ", pos);
    scanf("%d", &val);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = val;

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        iterator();
        return;
    }

    struct node *temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid index!\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    iterator();
}

// Delete at any index
void deleteAtAnyIndex(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 0) {
        struct node *ptr = head;
        head = head->next;
        free(ptr);
        iterator();
        return;
    }

    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < pos - 1; i++) {
        if (q == NULL) {
            printf("Invalid position!\n");
            return;
        }
        p = q;
        q = q->next;
    }
    p->next = q ? q->next : NULL;
    free(q);
    iterator();
}

// Delete node by value
void deleteByValue(int val) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *p = head;
    if (head->value == val) {
        head = head->next;
        free(p);
        printf("Deleted node with value %d\n", val);
        iterator();
        return;
    }

    struct node *prev = head;
    struct node *cur = head->next;
    while (cur != NULL) {
        if (cur->value == val) {
            prev->next = cur->next;
            free(cur);
            printf("Deleted node with value %d\n", val);
            iterator();
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("Value %d not found!\n", val);
}

// Main function
int main() {
    int nodeNo;
    printf("Enter the number of initial nodes: ");
    scanf("%d", &nodeNo);

    if (nodeNo <= 0) {
        printf("Invalid node number!\n");
        return 1;
    }

    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter value for node 1: ");
    scanf("%d", &head->value);
    cur = head;

    for (int i = 1; i < nodeNo; i++) {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &temp->value);
        cur->next = temp;
        cur = temp;
    }
    cur->next = NULL;

    iterator();

    // Menu-driven program
    char choice;
    do {
        printf("\nMenu:\n");
        printf("1) Insert at first (f)\n");
        printf("2) Insert at last (l)\n");
        printf("3) Insert in between (i)\n");
        printf("4) Delete by index (x)\n");
        printf("5) Delete by value (v)\n");
        printf("6) Exit (e)\n");
        printf("Enter your choice: ");
        getchar(); // clear buffer
        scanf("%c", &choice);

        switch (choice) {
            case 'f':
                insertAtFirst();
                break;
            case 'l':
                insertAtLast();
                break;
            case 'i': {
                int pos;
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insertInBetween(pos);
                break;
            }
            case 'x': {
                int pos;
                printf("Enter index to delete: ");
                scanf("%d", &pos);
                deleteAtAnyIndex(pos);
                break;
            }
            case 'v': {
                int val;
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteByValue(val);
                break;
            }
            case 'e':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 'e');

    return 0;
}
