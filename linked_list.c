#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    char* value;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

Node* new_node(char* value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error allocating memory to a new node");
    }

    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

int size() {
    int size = 0;
    Node* aux = head;

    while (aux != NULL) {
        size++;
        aux = aux->next;
    }

    return size;
}

void insert_last(Node* new_node) {
    Node* aux = head;

    if (aux == NULL) {
        aux = new_node;
    } else {
        while(aux->next != NULL) {
            aux = aux->next;
        }

        aux->next = (Node*) malloc(sizeof(Node));
        new_node->prev = aux;
        aux->next = new_node;
    }
}

// TODO - Add the insert at size() (Last index)
void insert_at(Node* new_node, int i) {
    if (i < 0 || i >= size()) {
        printf("Error! Select a valid index!\n");
        return;
    }

    Node* aux = head;
    for (int j = 0; j < i; j++) {
        aux = aux->next;
    }

    new_node->next = aux;
    new_node->prev = aux->prev;

    if (i == 0) {
        head = new_node;
    } else {
        aux->prev->next = new_node;
        aux->prev = new_node;
    }
}

void print_list() {
    Node* aux = head;

    while (aux != NULL) {
        printf("%s ", aux->value);
        aux = aux->next;
    }
}

void clear_list() {
    Node* aux = head;

    if (aux == NULL) {
        printf("The list is already clear");
    } else {
        while (aux->next != NULL) {
            aux = aux->next;
            free(aux->prev);
        }
        
        head = NULL;
    }
}

int main() {
    head = new_node("ESSA");
    printf("The size of the list is: %d\n", size()); // Should print 1

    Node* new = new_node("EH");
    insert_last(new);
    printf("The size of the list is: %d\n", size()); // Should print 2

    Node* new2 = new_node("UMA");
    insert_last(new2);

    Node* new3 = new_node("LINKED");
    insert_at(new3, 3);

    printf("\nThe size of the list is: %d\n", size()); // Should print 0

    print_list();
    clear_list();
    printf("\nThe size of the list is: %d\n", size()); // Should print 0
    return 0;
}