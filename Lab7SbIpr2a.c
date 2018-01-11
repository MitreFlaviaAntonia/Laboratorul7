#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;


void print_the_list()
{
    struct node *ptr = head;

    while(ptr != NULL) {
      printf(" %d ->",ptr->data);
      ptr = ptr->next;
   }
    printf(" NULL");

    }

void insert_link(int data)
{
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->next = head;
    head = link;
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
    int n;
    int i;
    int v[100];

    printf("How many components has the list?\n");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
   {
        printf("The next value in the list is: ");
        scanf("%d",&v[i]);
        insert_link(v[i]);
    }

   print_the_list();
   free_list(head);
   return 0;
}
