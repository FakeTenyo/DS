#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

// Function to insert an element into the circular queue
void enqueue(char value) {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue is full\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
}

// Function to delete an element from the circular queue
void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Element %c dequeued from queue\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Function to display the circular queue
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Circular Queue elements are:\n");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%c ", queue[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%c ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%c ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice;
    char value;
    do {
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf(" %c", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting from the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}