#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[3][3],i,j;
    printf("ENTER 9 ELMENTS FROM KEYBOARD\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("ELEMENTS IN 2-D ARRAY\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
