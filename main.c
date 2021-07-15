#include <stdio.h>
#include <stdlib.h>

int arr[9][9];

void fscan()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            scanf("%d",&arr[i][j]);
    }
}

void fprint()
{
    int n=9;

    for(int i=0; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(i%3==0)
            printf("  __ ");
        }
        printf("\n");
        printf("|");
        for(int j=0; j<n; j++)
        {
            printf(" %d  ",arr[i][j]);
            if((j+1)%3==0)
            printf("|");
        }
        printf("\n");
    }

    for(int j=1; j<n; j++)
    {
        printf("  __ ");
    }
}


int main()
{

    fscan();
    fprint();
    return 0;
}
