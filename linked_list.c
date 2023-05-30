#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main(int argc, char* argv[])
{
    Node root, element2;
    root.data = 10;
    root.next = &element2;
    element2.data = 11;
    element2.next = NULL;
    printf("First: %d\n", root.data);
    printf("Second: %d\n", root.next -> data);
    return 0;
}
