#include <stdio.h>
#include <stdlib.h>

int n;
int *p;
int i;

int main()
{
    printf ("Enter the length of the sequence :\n");
    scanf ("%d",&n);

    p = (int *) malloc( n * sizeof(int) );

    printf("Enter the sequence :\n");

    for (i=0;i<n;i++)
        scanf("%d",&p[i]);

    printf("\n");

    for (i=0;i<n;i++)
        printf ("%d ",p[i]);

    return 0;
}
