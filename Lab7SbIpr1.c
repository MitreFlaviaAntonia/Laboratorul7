#include <stdio.h>
#include <stdlib.h>

int length;
int *p;
int i;

int main()
{
    printf ( "Enter the length of the sequence : \n" );
    scanf ( "%d", &length );

    p = (int *) malloc( length * sizeof(int) );

    printf ( "Enter the sequence : \n" );

    for ( i = 0 ; i < length ; i++ )
        scanf( "%d", &p[i] );

    printf( "\n" );
    for ( i = 0 ; i < length ; i++ )
        printf ( "%d " , p[i] );

    return 0;
}
