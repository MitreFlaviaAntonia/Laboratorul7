#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void print_the_list(struct Node*head)
{
    struct node *ptr = head;

    while(ptr != NULL)
    {
        printf(" %d ->",ptr->data);
        ptr = ptr->next;
    }
    printf(" NULL");

}

void Sorted_Insert(struct node** head_ref, struct node* new_node)
{
    struct node* current;

    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL && current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

struct node *insert_link(int data)
{
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->next = NULL;
    return link;
}

void free_list(struct node* head)
{
   struct node* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}
int main()
{
    struct node *head = NULL;
    int x;
    int i;
    int sum=0;
    float average;
    struct node *new_node = NULL;

    for(i=0;i<=24;i++)
    {
        x=rand() % 100 ;
        sum=sum+x;
        printf("\nThe next value in the list is: %d",x);
        new_node = insert_link(x);
        Sorted_Insert(&head, new_node);
    }

    average=sum/25;

    printf("\nThe list after the insertion sort:\n");
    print_the_list(head);
    printf("\nThe sum of all the numbers in the list is: %d",sum);
    printf("\nThe average of all the numbers in the list is: %f",average);
    free_list(head);
    return 0;
}
