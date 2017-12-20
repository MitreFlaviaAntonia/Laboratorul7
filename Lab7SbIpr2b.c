#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data  = new_data;

    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;

    (*head_ref)    = new_node;
}

void insertAfter(struct node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("Add at least TWO elements in the list!!");
        return;
    }

    struct node* new_node =(struct node*) malloc(sizeof(struct node));

    new_node->data  = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;

    new_node->prev = prev_node;

    if (new_node->next != NULL)
      new_node->next->prev = new_node;
}

void append(struct node** head_ref, int new_data)
{

    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    struct node *last = *head_ref;

    new_node->data  = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }


    while (last->next != NULL)
        last = last->next;


    last->next = new_node;


    new_node->prev = last;

    return;
}

void print_list(struct node *node)
{
    struct node *last;
    printf("\nFrom left to right, the list is: \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nFrom right to left the list is: \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}


int main()
{
    struct node* head = NULL;
    int x=1;
    int element_from_list;
    int decision_value;
    printf("If you want to choose push, give the value 1 to decision_value\n");
    printf("If you want to choose append, give the value 2 to decision_value\n");
    printf("If you want to choose insert_after, give the value 3 to decision_value\n");
    printf("If you want to quit adding values, give the value 0 to decision_value\n");
    while(x!=0)
    {
        printf("Give the value for decision_value:\n\n");
        scanf("%d",&decision_value);
        if(decision_value!=0)
        {
            printf("Give the value for the element you want to introduce in the list:\n\n");
            scanf("%d",&element_from_list);
        }

        if(decision_value==1)
            push(&head, element_from_list);

        else
            if(decision_value==2)
                append(&head, element_from_list);

            else
                if(decision_value==3)
                    insertAfter(head->next, element_from_list);


        if(decision_value==0)
        {
            x=0;
        }

    }
    printf("The list is: ");
    print_list(head);

    getchar();
    return 0;
}
