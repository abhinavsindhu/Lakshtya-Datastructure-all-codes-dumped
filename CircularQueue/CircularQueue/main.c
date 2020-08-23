#include <stdio.h>
#include <stdlib.h>
struct CQUEUE
{
    int items[4];
    int front;
    int rear;
};
struct CQUEUE q;
struct CQUEUE *p=&q;

void Create();
void Insert(int);
void Delete();
void display();
void main()
{
    p->rear=-1;
    p->front=-1;
    int val;
    int ch;
     while(1)
   {
     printf("\n 1.INSERT");
     printf("\n 2.DELETE");
     printf("\n 3.DISPLAY");
     printf("\n 4.EXIT");
     printf("\n Enter your choice: ");
     scanf("%d",&ch);
     switch(ch)
     {
     case 1:

            printf("\n Enter a value to insert:");
            scanf("%d",&val);
            Insert(val);
            break;
     case 2:
            Delete();
            break;
     case 3:
            Display();
            break;
     case 4:
            exit(1);
            break;
     }
   }
 }

void Insert(int x)
{
    if((p->rear==3&&p->front==0)||(p->rear+1==p->front))
      {
          printf("\nCIRCULAR QUEUE IS FULL");
          exit(1);
      }
    if(p->front==-1)//INSERTION WHEN CQUEUE IS EMPTY
    {
        p->front=0;
        p->rear=0;
        p->items[p->rear]=x;
    }
    else if(p->rear==3)//
    {
        p->rear=0;
        p->items[p->rear]=x;
    }
    else
    {
        p->rear++;//INCRESE REAR VALUE AND THAT LOCATION PUT X
        p->items[p->rear]=x;

    }
    printf("\n Element inserted to queue...");
}
void Delete()
{
    if(p->front==-1)
    {
        printf("\n CIRCULAR QUEUE IS EMPTY");
        exit(1);
    }
    if(p->front==4)
    {
        p->front=0;
    }
    if(p->front==p->rear)
    {
        p->rear=-1;
        p->front=-1;
    }
    else
    {
        p->front++;
    }
}
void Display()
{
    int i;
    if(p->front==-1)
    {
        printf("\nCIRCULAR QUEUE IS EMPTY");
        exit(1);
    }
    if(p->rear>=p->front)
    {
        for(i=p->front;i<=p->rear;i++)
        {
            printf("\nitems[%d]:%d",i,p->items[i]);
        }
    }
    else
    {
        for(i=p->front;i<=4;i++)
        {
            printf("\nitems[%d]:%d",i,p->items[i]);
        }
        for(i=0;i<=p->rear;i++)
        {
            printf("\nitems[%d]:%d",i,p->items[i]);
        }

    }
}
