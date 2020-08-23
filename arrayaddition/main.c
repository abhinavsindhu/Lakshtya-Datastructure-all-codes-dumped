#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[3][3],B[3][3],C[3][3],i,j;
    printf("ENTER 9 ELMENTS FROM KEYBOARD IN ARRAY A\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
     printf("ENTER 9 ELMENTS FROM KEYBOARD IN ARRAY B\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    printf("AFTER ADDITION THE RESULTANT ARRAY IS\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

}
