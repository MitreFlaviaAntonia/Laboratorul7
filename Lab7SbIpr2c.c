#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;

   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;

   if(head == NULL)
    {
      return 0;
    }

   current = head->next;

    while(current != head)
    {
      length++;
      current = current->next;
    }

   return length;
}

void insert_first(int key, int data) {


   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;

   if (isEmpty()) {
      head = link;
      head->next = head;
   } else {

      link->next = head;

      head = link;
   }
}




void print_list() {

   struct node *ptr = head;
   printf("\n( ");


   if(head != NULL) {

      while(ptr->next != ptr) {
         printf("(%d,%d) ",ptr->key,ptr->data);
         ptr = ptr->next;
      }
   }

   printf(")");
}

int main() {
    insert_first(1, 2);
    int x=1;
    int element1;
    int element2;
    int decision_value;
    printf("If you want to choose to add another element to the list, give the value 1 to decision_value\n");
    printf("If you want to quit adding values, give the value 0 to decision_value\n");
    while(x!=0)
    {
        printf("Give the value for decision_value:\n\n");
        scanf("%d",&decision_value);
        if(decision_value!=0)
        {
            printf("Give the value for the elements you want to introduce in the list:\n\n");
            scanf("%d",&element1);
            scanf("%d",&element2);
        }

        if(decision_value==1)
            insert_first(element1, element2);

        if(decision_value==0)
        {
            x=0;
        }
    }

   printf("The list is: ");


   print_list();

}
