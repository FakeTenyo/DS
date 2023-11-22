#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to perform inorder traversal of the BST
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to perform preorder traversal of the BST
void preorderTraversal(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform postorder traversal of the BST
void postorderTraversal(struct Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Function to search for a key in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) return root;

    if (key < root->data) return search(root->left, key);
    
    return search(root->right, key);
}

// Function to find the minimum value node in a BST
struct Node* findMin(struct Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a node with the given value from the BST
struct Node* deleteNode(struct Node* root, int elem) {
    if (root == NULL) return root;

    if (elem < root->data) {
        root->left = deleteNode(root->left, elem);
    } else if (elem > root->data) {
        root->right = deleteNode(root->right, elem);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;

    // Create a BST of N Integers
    int elements[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    int n = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }
    printf("Menu:\n");
    printf("1. Traverse the BST (Inorder)\n");
    printf("2. Traverse the BST (Preorder)\n");
    printf("3. Traverse the BST (Postorder)\n");
    printf("4. Search for an element\n");
    printf("5. Delete an element\n");
    printf("6. Exit\n");

    int choice, key, elem;
    do {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    printf("Element %d found in the BST.\n", key);
                } else {
                    printf("Element %d not found in the BST.\n", key);
                }
                break;
            case 5:
                printf("Enter the element to delete: ");
                scanf("%d", &elem);
                root = deleteNode(root, elem);
                printf("Element %d deleted from the BST.\n", elem);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}