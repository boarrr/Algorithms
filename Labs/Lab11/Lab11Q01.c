#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

void insert_data(struct Node **root, int data);  // Notice the double pointer
void print_tree(struct Node *root);

int main(void)
{
    struct Node *root = NULL;
    int test_data[SIZE] = {7, 9, 13, 10, 8, 1, 2, 3};

    for (int i = 0; i < SIZE; i++) {
        insert_data(&root, test_data[i]);  // Pass the address of root
    }

    print_tree(root);

    return 0;
}

// Insert data into the BST
void insert_data(struct Node **root, int data)
{
    struct Node *new = malloc(sizeof(struct Node));

    // If allocation fails
    if (new == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    new->data = data;
    new->left = NULL;
    new->right = NULL;

    if (*root == NULL) {
        *root = new; 
        return;
    }

    struct Node *current = *root;
    struct Node *parent = NULL;

    // Loop through tree and find the correct position for the new node
    while (current != NULL) {

        parent = current;

        if (data < current->data) {
            current = current->left;

            if (current == NULL) {
                parent->left = new;
                return;
            }
        } 
        else {
            current = current->right;
            if (current == NULL) {
                parent->right = new;
                return;
            }
        }
    }
}

void print_tree(struct Node *root)
{
    if (root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}
