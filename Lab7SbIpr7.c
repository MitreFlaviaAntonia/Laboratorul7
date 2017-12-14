#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[30];
int length;
int top = -1;
char ch;

void push ( char ch );
void pop();
char top1();


int main()
{
    printf ( "Enter the maximum length of the stack: \n");
    scanf ( "%d", &length );

    printf ( "\nEnter the string: \n" );

    do
    {
        scanf ( "%c" , &ch );
        push( ch );
    }
    while ( top < length );

    printf ( "\nThe reverse of this string : \n ");

    while ( top != -1 )
    {
        printf ( "%c" , top1() );
        pop();
    }

    return 0;
}

void push( char ch )
{
    top ++;
    arr[ top ] = ch;
}

void pop()
{
    top --;
}

char top1()
{
    return arr[top];
}
