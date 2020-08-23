#include <stdio.h>
#include <stdlib.h>
int count=0;
struct STACK
{
    int items[20];
    int top;
};
struct STACK s;
struct STACK *p=&s;
struct LINKEDLIST
{
    int info;
    struct LINKEDLIST *next;
};
struct LINKEDLIST *start=NULL;
void push(int);
int pop();
void create();
void Display();
int main()
{   char ch;
    p->top=-1;
    printf("DO YOU WANT TO CREATE A NODE\n");
    scanf("%c",&ch);

    while(ch=='y')
    {
        Create();
        count++;
        printf("DO YOU WANT TO CREATE A NODE(y/n)\n");
        fflush(stdin);
        scanf("%c",&ch);
    }
    Display();
    checkPallindrome();



    return 0;
}
void Create()
{
  struct LINKEDLIST *temp;
  int x;
 if(start==NULL)
 {
     temp=(struct LINKEDLIST*)malloc(sizeof(struct LINKEDLIST));
    if(temp==NULL)
    {
        printf("OUT OF MEMORY\n");
        exit(1);
    }
    else
    {   start=temp;
        temp->next=NULL;
        printf("\nENTER DATA INTO THE NODE\n");
        scanf("%d",&x);
        temp->info=x;
    }
 }
  else
  {   temp=start;
      while(temp->next!=NULL)
      {
          temp=temp->next;
      }
      temp->next=(struct LINKEDLIST*)malloc(sizeof(struct LINKEDLIST));
      if(temp->next==NULL)
      {
        printf("OUT OF MEMORY\n");
        exit(1);
      }
      temp=temp->next;
      temp->next=NULL;
      printf("\nENTER DATA INTO THE NODE\n");
      scanf("%d",&x);
      temp->info=x;
  }

}
void Display()
{
    struct LINKEDLIST *temp1=start;
    while(temp1!=NULL)
    {
        printf("%d ",temp1->info);
        temp1=temp1->next;
    }
}
void TraversalandPush()
{
    struct LINKEDLIST *trav=start;
    while(trav!=NULL)
    {
        push(trav->info);
        trav=trav->next;

    }
}
void push(int x)
{
   if(p->top==19)
   {
       printf("STACK IS FULL\n");
       exit(1);
   }
   p->top++;
   p->items[p->top]=x;

}
int pop()
{   int x;
    if(p->top==-1)
    {
        printf("STACK IS EMPTY\n");
        exit(1);
    }
    x=p->items[p->top];
    p->top--;
    return x;
}
void checkPallindrome()
{    struct LINKEDLIST *tr=start;
     TraversalandPush();
     while(tr!=NULL)
     {
        if(tr->info!=pop())
        {
            printf("\nLINKED LIST IS NOT A PALLINDROME\n");
            exit(1);
        }
        tr=tr->next;

     }
     printf("LINKED LIST IS PALLINDROME");

}
