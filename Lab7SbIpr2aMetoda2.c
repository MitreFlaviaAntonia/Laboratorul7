#include<stdio.h>
#include<stdlib.h>

struct node *head = NULL;

struct node
{
    int data;
    struct node* next;
};

void push(struct node** head_ref, int new_data)
{

    struct node* link = (struct node*) malloc(sizeof(struct node));
    link->data  = new_data;
    link->next = (*head_ref);
    (*head_ref) = link;
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
    int i,n,x,y;

    struct node* head = NULL;
    printf("Give the number of components: ");
    scanf("%d",&n);

    printf("\nEnter %d elements in the list: ",n);
     for(i=0;i<=n-1;i++)
     {
        scanf("%d",&x);
        push(&head, x);
     }
    free_list(head);
    return 0;
}
