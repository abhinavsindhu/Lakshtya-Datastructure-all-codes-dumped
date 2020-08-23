#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=1,y=3,z=5;
    if(x>1)
        printf("LINE 1");
    else
        if(z<3)
        {
         printf("LINE 2");
           if(y<3)
             if(x==1)
             printf("LINE 3");
             else
             printf("LINE 4");
        }
        else
            if(z>7)
           {
            printf("LINE 5");
              if(y>1)
               if(x==3)
               printf("LINE 6");
               else
               printf("LINE 7");
           }
            else
           {
             printf("LINE 9");
           }
        printf("LINE 8");
    return 0;
}
