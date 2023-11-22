#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coeff_x, coeff_y, coeff_z;
    int power_x, power_y, power_z;
    struct Node *next;
};

typedef struct Node Node;

// Function to create a new node
Node *createNode(int cx, int cy, int cz, int px, int py, int pz) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->coeff_x = cx;
    newNode->coeff_y = cy;
    newNode->coeff_z = cz;
    newNode->power_x = px;
    newNode->power_y = py;
    newNode->power_z = pz;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new term into the polynomial
Node *insertTerm(Node *poly, int cx, int cy, int cz, int px, int py, int pz) {
    Node *newNode = createNode(cx, cy, cz, px, py, pz);
    if (poly == NULL) {
        newNode->next = newNode;  // Make it circular
        poly = newNode;
    } else {
        Node *temp = poly;
        while (temp->next != poly)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = poly;
    }
    return poly;
}

// Function to display a polynomial
void displayPolynomial(Node *poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    Node *temp = poly;
    do {
        printf("%dx^%dy^%dz^%d", temp->coeff_x, temp->power_x, temp->power_y, temp->power_z);
        temp = temp->next;
        if (temp != poly) {
            printf(" + ");
        } else {
            printf("\n");
        }
    } while (temp != poly);
}

// Function to evaluate a polynomial for given values of x, y, and z
int evaluatePolynomial(Node *poly, int x, int y, int z) {
    if (poly == NULL) {
        return 0;
    }
    int result = 0;
    Node *temp = poly;
    do {
        result += temp->coeff_x * pow(x, temp->power_x) * temp->coeff_y * pow(y, temp->power_y) * temp->coeff_z * pow(z, temp->power_z);
        temp = temp->next;
    } while (temp != poly);
    return result;
}

// Function to add two polynomials and store the result in another polynomial
Node *addPolynomials(Node *poly1, Node *poly2) {
    Node *polySum = NULL;
    Node *temp1 = poly1, *temp2 = poly2;

    if (temp1 != NULL) {
        do {
            polySum = insertTerm(polySum, temp1->coeff_x, temp1->coeff_y, temp1->coeff_z, temp1->power_x, temp1->power_y, temp1->power_z);
            temp1 = temp1->next;
        } while (temp1 != poly1);
    }

    if (temp2 != NULL) {
        do {
            polySum = insertTerm(polySum, temp2->coeff_x, temp2->coeff_y, temp2->coeff_z, temp2->power_x, temp2->power_y, temp2->power_z);
            temp2 = temp2->next;
        } while (temp2 != poly2);
    }

    return polySum;
}

int main() {
    Node *poly1 = NULL;
    Node *poly2 = NULL;

    poly1 = insertTerm(poly1, 2, 3, 0, 1, 2, 0);  // 2x^1y^2z^0
    poly1 = insertTerm(poly1, 3, 0, 1, 0, 0, 1);  // 3xz

    poly2 = insertTerm(poly2, 1, 1, 1, 2, 1, 3);  // x^2yz^3
    poly2 = insertTerm(poly2, 2, 1, 1, 1, 2, 2);  // 2xy^2z^2

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    int result = evaluatePolynomial(poly1, 2, 3, 1);
    printf("Result of evaluating Polynomial 1: %d\n", result);

    Node *polySum = addPolynomials(poly1, poly2);
    printf("Sum of Polynomial 1 and Polynomial 2: ");
    displayPolynomial(polySum);

    return 0;
}