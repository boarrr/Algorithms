/*
  Description: A program which uses a linked list to store a random number of random numbers
  Author: Ryan Pitman
  Date: 09/04/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ll_number {
    int num;
    struct ll_number *next;
};

struct ll_number *head = NULL;

int random_int_100();
int insert_num(int data);
struct ll_number *create_node(int data);
void insert_nums(int count);
void print_list();
void free_list();

int main(void)
{
    srand(time(0));

    insert_nums(random_int_100());

    print_list();

    free_list();
    
    return 0;
}

// Return a random int between 0 and 100
int random_int_100()
{
    return rand() % 100;
}

// Insert a number into the list in sorted order
int insert_num(int data)
{
    struct ll_number *new_node = create_node(data);
    if (new_node == NULL) {
        return -1;
    }

    // If the list is empty or the new node should be placed before the head
    if (head == NULL || data < head->num) {
        new_node->next = head;
        head = new_node;
    } else {
        struct ll_number *current = head;
        // Find the correct position for the new node
        while (current->next != NULL && current->next->num < data) {
            current = current->next;
        }
        // Insert the new node
        new_node->next = current->next;
        current->next = new_node;
    }

    return 0;
}

// Create a new node
struct ll_number *create_node(int data)
{
    struct ll_number *new = (struct ll_number *)malloc(sizeof(struct ll_number));
    if (new == NULL) {
        return NULL;
    }
    new->num = data;
    new->next = NULL;
    return new;
}

// Insert count numbers into the list
void insert_nums(int count)
{
    for (int i = 0; i < count; i++) {
        int random_num = random_int_100();
        if (insert_num(random_num) != 0) {
            printf("\nProgram failed! Exiting...\n");
            return;
        }
    }
}

// Display all elements in the list
void print_list()
{
    struct ll_number *tmp = head;

    printf("\n---Displaying List---\n");

    while (tmp != NULL) {
        printf("%d->", tmp->num);
        tmp = tmp->next;
    }

    printf("END\n");
}

// Free the list at the end of program execution
void free_list() 
{
    struct ll_number *tmp = head;
    
    while (tmp != NULL) {
        struct ll_number *next = tmp->next; 
        free(tmp); 
        tmp = next; 
    }
    
    head = NULL;
}
