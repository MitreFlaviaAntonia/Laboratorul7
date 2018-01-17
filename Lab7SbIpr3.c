#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node *next;
};

struct node *the_head_of_the_first_list = NULL;
struct node *current1 = NULL;
struct node *the_head_of_the_second_list;
struct node *current2 = NULL;

void concatenate ( struct node **p, struct node **q )
{
    struct node *temp ;


if ( *p == NULL )
        *p = *q ;
    else
    {

        if ( *q != NULL )
        {
            temp = *p ;

            while ( temp -> next != NULL ) temp = temp -> next ;
                temp -> next = *q ;
        }
    }
}

void print_the_list1()
{
  struct node *ptr = the_head_of_the_first_list;

   printf("\nThe head of the first list ->");

    while(ptr != NULL)
    {
      printf(" %d ->",ptr->data);
      ptr = ptr->next;
    }

   printf(" NULL\n");
}

void print_the_list2()
{
    struct node *ptr = the_head_of_the_second_list;

    printf("\nThe head of the second list ->");

    while(ptr != NULL)
    {
      printf(" %d ->",ptr->data);
      ptr = ptr->next;
    }

   printf(" NULL\n");
}

void insert_link1(int data)
{
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->next = the_head_of_the_first_list;
    the_head_of_the_first_list = link;
}

void insert_link2(int data)
{
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->next = the_head_of_the_second_list;
    the_head_of_the_second_list = link;
}


int main()
 {
    int n;
    int m;
    int i;
    int v[100];
    int w[100];

    printf("How many components has the first list?\n");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("The next value in the list is: ");
        scanf("%d",&v[i]);
        insert_link1(v[i]);
    }

    printf("How many components has the second list?\n");
    scanf("%d",&m);

    for(i=1;i<=m;i++)
    {
        printf("The next value in the list is: ");
        scanf("%d",&w[i]);
        insert_link2(w[i]);
    }


   print_the_list1();
   print_the_list2();
   concatenate(&the_head_of_the_first_list,&the_head_of_the_second_list);
   print_the_list1();
   return 0;
}
