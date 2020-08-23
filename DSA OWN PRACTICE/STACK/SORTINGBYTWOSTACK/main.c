#include <stdio.h>
#include <stdlib.h>

struct STACK
{
    int items[30];
    int top;
};
void SortStack(struct STACK *,struct STACK *);
void push(struct STACK *,int );
int pop(struct STACK *);
void display(struct STACK *);
int peek(struct STACK *);

int main()
{   struct STACK S1,S2;
    S1.top=-1;
    S2.top=-1;
    int size,i,x;
    printf("\nENTER NO OF ELEMENTS YOU WANT TO INSERT IN STACK\n");
    scanf("%d",&size);

    for(i=0;i<size;i++)
    {
        scanf("%d",&x);
        push(&S1,x);
    }
    SortStack(&S1,&S2);
    display(&S2);
    return 0;
}
void push(struct STACK *p,int x)
{
    if(p->top==29)
    {
        printf("STACK IS FULL");
        exit(1);
    }
    p->top++;
    p->items[p->top]=x;
    printf("PUSHED %d\n",x);

}
int pop(struct STACK *a)
{   int temp;
    if(a->top==-1)
    {
        printf("STACK IS EMPTY");
        exit(1);
    }
    temp=a->items[a->top];
    a->top--;
    printf("POP %d \n",temp);
    return temp;
}
void display(struct STACK *p)
{  int t;
    t=p->top;
    printf("\nELEMENTS IN STACK\n");
    while(p->top!=-1)
    {
        printf("%d \n",p->items[p->top]);
        p->top--;
    }
    p->top=t;
}
int peek(struct STACK *a)
{
   return a->items[a->top];
}
void SortStack(struct STACK *p,struct STACK *s)
{ int temp,count;
  temp=pop(p);
  printf("Temp=%d \n",temp);
  push(s,temp);
  while(p->top!=-1)
  {  count=0;
     if(peek(p)<peek(s))
     {
       printf("TOP MOST OF ORIGINAL STACK=%d\n",peek(p));
       printf("TOP MOST OF EXTRA STACK=%d\n",peek(s));
       temp=pop(p);
       printf("Temp=%d \n",temp);
       while(s->top!=-1&&temp<peek(s))
      {   printf("TEMP(%d)<TOPMOST OF EXTRA ST(%d)\n",temp,peek(s));
          count++;
          push(p,pop(s));
      }
      push(s,temp);
      while(count>0)
      {
          push(s,pop(p));
          count--;
      }
    }
     else
    {
      push(s,pop(p));
    }
  }

}

