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
    printf("]");
}

void print(Node* tail, Node* head)
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
    tail -> next -> data = 2;
    tail -> next -> prev = tail;
    tail -> next -> next = malloc(sizeof(Node));
    if (tail -> next -> next == NULL)
    {
        return 3;
    }

    tail -> next -> next -> data = 3;
    tail -> next -> next -> prev = tail -> next;
    tail -> next -> next -> next = NULL;
    Node* head = tail -> next -> next;

    print(tail);
    print(tail, head);

    return 0;
}
