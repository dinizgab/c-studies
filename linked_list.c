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
 
int size() {
    int size = 0;
    Node* aux = head;

    while (aux != NULL) {
        size++;
        aux = aux->next;
    }

    return size;
}

int main() {
    head = new_node("ESSA");
    printf("The size of the list is: %d\n", size()); // Should print 1
    printf("%s\n", head->value);

    Node* new = new_node("EH");
    insert_last(new);

    printf("The size of the list is: %d\n", size()); // Should print 2
    printf("%s\n", head->next->value);

    clear_list();
    printf("The size of the list is: %d\n", size()); // Should print 0
    return 0;
}