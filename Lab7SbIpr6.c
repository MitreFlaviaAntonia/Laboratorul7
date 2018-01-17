#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char info; /*At least I tried*/
    struct node * next;
};

int i;

int main()
{
    char x;
    struct node * link = ( struct node *) malloc( sizeof( struct node) );
    link -> next = NULL;

    struct node * head = link;

    for( i = 0 ; i < 10 ; i++ )
    {
        printf("Write a char: ");
        scanf("%c",&x);
        struct node * newNode = ( struct node *) malloc( sizeof( struct node) );
        newNode -> next = NULL;
        newNode -> info = x;

        link -> next = newNode;
        link = newNode;
    }

    link = head;
    printf( "\nThe list: ");
    while( link -> next )
    {
        link = link -> next;
        printf( "\n%d", link -> info );
    }

    struct node * copy_link = ( struct node *) malloc( sizeof( struct node) );
    copy_link -> info = link -> info;
    copy_link -> next = NULL;

    struct node * head2 = copy_link;

    link = head;

    while( link -> next )
    {
        link = link -> next;

        struct node * newNode = ( struct node *) malloc( sizeof( struct node) );
        newNode -> info = link -> info;

        newNode -> next = copy_link;
        copy_link = newNode;
    }

    printf( "\nThe copy of the list : ");
    while( copy_link -> next )
    {
        printf( "\n%d", copy_link -> info );
        copy_link = copy_link -> next;
    }

    while( head -> next )
    {
        link = head -> next;
        free( head );
        head = link;
    }

    while( head2 -> next )
    {
        link = head2 -> next;
        free( head2 );
        head2 = link;
    }


    return 0;
}
