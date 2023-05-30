#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print(Node root)
{
    printf("List:\n[ ");
    for(Node* current = &root; current != NULL; current = current -> next)
    {
        printf("%d ", current -> data);
    }
    printf("]\n");
}



int main(int argc, char* argv[])
{
    Node root;
    root.data = 10;
    root.next = malloc(sizeof(Node));
    root.next -> data = 11;
    root.next -> next = NULL;

    print(root)
    free(root.next);
    return 0;
}
