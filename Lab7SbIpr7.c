#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[50];
char x;
int length;
int up = -1;

void push(char x)
{
    up ++;
    arr[up]=x;
}

int main()
{
    printf("The length of the string is:\n");
    scanf("%d",&length);

    printf("\nThe string is: \n");
    do
    {
        scanf("%c",&x);
        push(x);
    }
    while(up<length);

    printf("\nThe reverse of the string is:\n");

    while(up!=-1)
    {
        printf("%c",arr[up]);
        up--;
    }

    return 0;
}


