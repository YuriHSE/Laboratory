// 26 вариант

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int d;
    int c;
    struct Node *next;
} Node;


Node* createNode(int d, int c) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->d = d;
    newNode->c = c;
    newNode->next = NULL;
    return newNode;
}


void appendNode(Node **head, int d, int c) {
    Node *newNode = createNode(d, c);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%dx^%d ", current->c, current->d);
        current = current->next;
        if (current != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}


void freeList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}


Node* mergePolynomials(Node *L1, Node *L2) {
    Node *result = NULL;
    Node *current1 = L1;
    Node *current2 = L2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->d == current2->d) {
            appendNode(&result, current1->d, current1->c + current2->c);
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->d < current2->d) {
            current1 = current1->next;
        } else {
            current2 = current2->next;
        }
    }
    return result;
}

void inputPolynomial(Node **poly) {
    int n;
    printf("Введите количество членов многочлена: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int d, c;
        printf("Введите степень и коэффициент члена %d (например, '2 3' для 3x^2): ", i + 1);
        scanf("%d %d", &d, &c);
        appendNode(poly, d, c);
    }
}

int main() {
    Node *L1 = NULL;
    Node *L2 = NULL;

    printf("Ввод многочлена L1:\n");
    inputPolynomial(&L1);

    printf("Ввод многочлена L2:\n");
    inputPolynomial(&L2);

    printf("Исходный многочлен L1: ");
    printList(L1);

    printf("Исходный многочлен L2: ");
    printList(L2);

    Node *result = mergePolynomials(L1, L2);

    printf("Результирующий многочлен: ");
    printList(result);

    // Освобождение памяти
    freeList(L1);
    freeList(L2);
    freeList(result);

    return 0;
}
