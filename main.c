#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int arr[9][9];
int n=4;
int error=0;

void fscan()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            scanf("%d",&arr[i][j]);
    }
}

void fprint()
{
    int rootn = sqrt(n);
    printf("\t\t");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i%rootn==0)
            printf(" __ ");
        }
        printf("\n\t\t");
        printf("|");
        for(int j=0; j<n; j++)
        {
            printf(" %d  ",arr[i][j]);
            if((j+1)%rootn==0)
            printf("|");
        }
        printf("\n\t\t");
    }

    for(int j=0; j<=n; j++)
    {
        printf(" __ ");
    }
}

void rowCheck(a,row,col)
{
    for (int i=0;i<n;i=i+1)
    {
        if (col==i)
        {
            continue;
        }
        else
        {
            if (arr[row][i]==a)
            {
                printf("\n\t\t\tERROR");
                printf("\n\t\t%d repeated in %d%d and %d%d",a,row,col,row,i);
                error=error+1;
            }
        }
    }

}
void colCheck(a,row,col)
{
    for (int i=0;i<n;i=i+1)
    {
        if (row==i)
        {
            continue;
        }
        else
        {
            if (arr[i][col]==a)
            {
                printf("\n\t\t\tERROR");
                printf("\n\t\t%d repeated in %d%d and %d%d",a,row,col,i,col);
                error=error+1;
            }
        }
    }
}
void boxCheck(a,row,col)
{
    int rootn = sqrt(n);
    int rowcorner=rootn*(row/rootn);
    int colcorner=rootn*(col/rootn);
    int rl=rowcorner+rootn;
    int cl=colcorner+rootn;
    for (int i=rowcorner;i<rl;i=i+1)
    {
        for (int j=colcorner;j<cl;j=j+1)
        {
            if (row==i || col==j)
            {
                continue;
            }
            else
            {
                if (arr[i][j]==a)
                {
                    printf("\n\t\t\tERROR");
                    printf("\n\t\t%d repeated in %d%d and %d%d",a,row,col,i,j);
                    error=error+1;
                }
            }
        }
    }
}
void fcheck()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
                rowCheck(arr[i][j],i,j);
                colCheck(arr[i][j],i,j);
                boxCheck(arr[i][j],i,j);
        }
    }
    if (error==0)
    {
        printf("\n\t\t\tNO ERROR");
    }
    printf("\n");
}


int main()
{
    fscan();
    fprint();
    fcheck();
//    printSudoku()
    return 0;
}
