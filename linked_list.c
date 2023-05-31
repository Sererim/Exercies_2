#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print(Node* root)
{
    printf("List:\n[ ");
    for(Node* current = root; current != NULL; current = current -> next)
    {
        printf("%d ", current -> data);
    }
    printf("]\n");
}

void push(Node** root, int val)
{
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
    }

    new_node -> next = NULL;
    new_node -> data = val;

    if (*root == NULL)
    {
        *root = new_node;
        return;
    }

    Node* curr = *root;
    while (curr -> next != NULL)
    {
        curr = curr -> next;
    }
    curr -> next = new_node;
}

void deallocate(Node** root)
{
    Node* temp = NULL;
    for (Node* curr = *root; curr != NULL; curr = curr -> next) 
    {
        temp = curr;
        free(temp);
    }
    *root = NULL;
}

void reverse(Node** root)
{
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = *root;

    while (curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        
        prev = curr;
        curr = next;
    }

    *root = prev;
}

int main(int argc, char* argv[])
{
    Node* root = malloc(sizeof(Node));
    if (root == NULL)
    {
        exit(2);
    }
    
    push(&root, 1);
    push(&root, 2);
    push(&root, 3);
    push(&root, 4);
    push(&root, 5);
    push(&root, 6);
    print(root);
    
    reverse(&root);
    print(root);
    
    deallocate(&root);
    return 0;
}