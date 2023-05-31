#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void print(Node* tail)
{
    printf("[ ");
    for (Node* curr = tail; curr != NULL; curr = curr -> next)
    {
        printf("%d ", curr -> data);
    }
    printf("]\n");
}

void print_d(Node* tail, Node* head)
{
    Node* curr = tail;
    Node* urr = head;
    while (curr != NULL && urr != NULL)
    {
        printf("%d %d\n", curr -> data, urr -> data);
        curr = curr -> next;
        urr = urr -> prev;
    }
}

void push(Node** head, int val)
{
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return;
    }

    new_node -> data = val;
    new_node -> next = NULL;
    new_node -> prev = *head;
    (*head) -> next = new_node;
    *head = new_node;
}

void deallocate(Node** tail, Node** head)
{
    if (*tail == NULL)
    {
        return;
    }

    Node* curr = *tail;
    while (curr -> next != NULL)
    {
        curr = curr -> next;
        free(curr -> prev);
    }
    free(curr);
    
    *tail = NULL;
    *head = NULL;
}

int main(int argc, char* argv[])
{
    Node* tail = malloc(sizeof(Node));
    if (tail == NULL)
    {
        return 1;
    }

    tail -> data = 1;
    tail -> prev = NULL;
    tail -> next = malloc(sizeof(Node));
    if (tail -> next == NULL)
    {
        return 2;
    }
    Node* head = tail -> next;

    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    
    print(tail);
    print_d(tail, head);

    deallocate(&tail, &head);
    return 0;
}
