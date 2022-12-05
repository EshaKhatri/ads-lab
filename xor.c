#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node {
    int item;
    struct node *link;
} node;

node *head, *tail;

node *xor(node *a, node *b)
{
    return (node*) ((uintptr_t) a ^ (uintptr_t) b);
}

void insert(int item)
{
    node *ptr = (node*) malloc(sizeof(node));
    ptr->item = item;

    if (NULL == head) {
        ptr->link = NULL;
        head = tail = ptr;
    } else{
        ptr->link = xor(tail, NULL);
        tail->link = xor(ptr, xor(tail->link, NULL));
        tail = ptr;
    }
}
int delete()
{
    int item;
    node *ptr;
    if (NULL == head) {
        printf("Empty list.\n");
        exit(1);
    } else {
        ptr = tail;
        item = ptr->item;
        node *prev = xor(ptr->link, NULL);
        if (NULL == prev) head = NULL;
        else prev->link= xor(ptr, xor(prev->link, NULL));
        tail = prev;

    }
    free(ptr);
    ptr = NULL;
    return item;
}

void display()
{
    node *curr = head;
    node *prev = NULL, *next;

    printf("\nList elements are : ");
    while (NULL != curr) {
        printf("%d ", curr->item);
        next = xor(prev, curr->link);
        prev = curr;
        curr = next;
    }

    printf("\n");
}

int main()
{
    int value;
    int choice;
    while(1)
    {
    printf(" \n1.Insert \n");
    printf("2.Delete \n");
    printf("3.Display \n");
    printf("4.Exit \n");
    printf("Enter your choice : ");
    scanf("%d",&choice);

    switch (choice)
        {
            case 1 :
            printf("Enter the value : ");
            scanf("%d",&value);
            insert(value);
            break;
            case 2 :
            delete();
            break;
            case 3 :
            display();
            break;
            case 4 :
            exit(1);
            break;
            default:
            printf("Invalid choice \n");
        }

    }

}
