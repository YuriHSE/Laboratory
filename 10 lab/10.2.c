// 26 варинат

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Node {
    char *word;
    struct Node *prev;
    struct Node *next;
} Node;


Node* createNode(char *word) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->word = strdup(word);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void appendNode(Node **head, Node **tail, char *word) {
    Node *newNode = createNode(word);
    if (*tail) {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    } else {
        *head = *tail = newNode;
    }
}


void printList(Node *head) {
    Node *current = head;
    while (current) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}


int first(char *word) {
    char a = tolower(word[0]);
    return a == 'a' || a == 'e' || a == 'i' || 
           a == 'o' || a == 'u' || a == 'y';
}


void move(Node **head, Node **tail) {
    Node *current = *head;
    Node *newHead = NULL;
    Node *newTail = NULL;
    Node *temp;

    while (current) {
        temp = current->next;
        if (first(current->word)) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                *tail = current->prev;
            }
            current->prev = NULL;
            current->next = newHead;
            if (newHead) {
                newHead->prev = current;
            }
            newHead = current;
            if (!newTail) {
                newTail = current;
            }
        }
        current = temp;
    }
    if (newTail) {
        newTail->next = *head;
        if (*head) {
            (*head)->prev = newTail;
        }
        *head = newHead;
    }
    if (*tail == NULL) {
        *tail = newTail;
    }
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    char input[1000];

    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " .\n");
    while (token) {
        appendNode(&head, &tail, token);
        token = strtok(NULL, " .\n");
    }

    printf("Исходный список: ");
    printList(head);

    move(&head, &tail);

    printf("Новый список: ");
    printList(head);


    Node *current = head;
    while (current) {
        Node *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }

    return 0;
}
