#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->value = value;
        newNode->next = NULL;
    }
    return newNode;
}

void insert_end(Node* head[], int value) {
    Node* newNode = createNode(value);
    if (newNode != NULL) {
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node* current_node = *head;
            while (current_node->next != NULL) {
                current_node = current_node->next;
            }
            current_node->next = newNode;
        }
    } else {
        printf("Error : Create a new node is impossible.\n");
    }
}

void afficherListe(Node* head) {
    Node* current_node = head;
    printf("Values of the linked list :\n");
    while (current_node != NULL) {
        printf("%d\n", current_node->value);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

void insert_start(Node* head[], int value) {
    Node* newNode = createNode(value);
    if (newNode != NULL) {
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node* current_node = *head;
            newNode->next = current_node;
            *head = newNode;
        }
    } else {
        printf("Error : Create a new node is impossible.\n");
    }
}

void delete_element(Node* head[], int value){
    Node* current_node = head;
    if (current_node->value == value){
        *head = current_node->next;
    }else{
        while (current_node->next->value != value) {
            current_node = current_node->next;
        }
        current_node->next = current_node->next->next;
    }

}


int main() {
    Node* head = NULL;

    int x;
    printf("Choose the size of your linked list :\n");
    scanf("%d", &x);
    for (int i = 0; i < x; ++i) {
        insert_end(&head, i+1);
    }

    printf("liste de départ :");
    afficherListe(head);

    printf("liste en ajoutant au debut :");
    insert_start(&head, 9);
    afficherListe(head);

    printf("liste en enlevant une valeur :");
    delete_element(head, 2);
    afficherListe(head);

    // Liberation de la memoire
    while (head != NULL) {
        Node* temporary = head;
        head = head->next;
        free(temporary);
    }

    return 0;
}