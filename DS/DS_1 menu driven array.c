#include <stdio.h>

// Function to create an array of N integer elements
void createArray(int arr[], int N) {
    printf("Enter %d elements:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display array elements with suitable headings
void displayArray(int arr[], int N) {
    printf("Array Elements:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element (ELEM) at a given valid position (POS)
void insertElement(int arr[], int *N, int elem, int pos) {
    if (pos < 0 || pos > *N) {
        printf("Invalid position. Element not inserted.\n");
        return;
    }
    
    for (int i = *N; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = elem;
    (*N)++;
    printf("Element inserted successfully.\n");
}

// Function to delete an element at a given valid position (POS)
void deleteElement(int arr[], int *N, int pos) {
    if (pos < 0 || pos >= *N) {
        printf("Invalid position. Element not deleted.\n");
        return;
    }
    
    for (int i = pos; i < *N - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*N)--;
    printf("Element deleted successfully.\n");
}


int main() {
    int choice, N;

    printf("Enter the size of the array: ");
    scanf("%d", &N);
    int arr[N];
    
    createArray(arr, N);
    
int elem, pos;

while (1) {
    printf("\nMenu:\n");
    printf("1. Display Array\n");
    printf("2. Insert Element\n");
    printf("3. Delete Element\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            displayArray(arr, N);
            break;
        case 2:
            // int elem, pos; // Remove this line from here
            printf("Enter the element to insert: ");
            scanf("%d", &elem);
            printf("Enter the position to insert at: ");
            scanf("%d", &pos);
            insertElement(arr, &N, elem, pos);
            break;
        case 3:
            printf("Enter the position to delete from: ");
            scanf("%d", &pos);
            deleteElement(arr, &N, pos);
            break;
        case 4:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

    return 0;
}
