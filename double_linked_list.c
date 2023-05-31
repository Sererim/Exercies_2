#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

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

    return 0;
}
