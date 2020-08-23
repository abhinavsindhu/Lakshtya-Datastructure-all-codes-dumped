#include <stdio.h>
#include <stdlib.h>
struct STACK
{
    int items[6];
    int top;
};

void push(int,struct STACK*);
int pop(struct STACK*);
void filter(struct STACK*,struct STACK*);
void disp(struct STACK *);
int main()
{
    struct STACK A,B;
    A.top=B.top=-1;
    int i=0,el;
    printf("ENTERING 10 ALTERNATE ELEMENTS IN STACK");
    for(i=0;i<6;i++)
    {
      scanf("%d",&el);
      push(el,&A);
    }
    printf("FILTERING ELEMENTS IN STACK\n");
    disp(&A);
    filter(&A,&B);
    printf("STACK A CONTAINS\n");
    disp(&A);
    printf("STACK B CONTAINS\n");
    disp(&B);

    return 0;
}
void push(int E,struct STACK *S)
{
    if(S->top==5)
    {
        printf("\nSTACK IS FULL\n");
        exit(1);
    }
    S->top++;
    S->items[S->top]=E;
}
int pop(struct STACK *P)
{  int de;
    if(P->top==-1)
    {
        printf("\nSTACK IS EMPTY\n");
        exit(1);
    }
    de=P->items[P->top];
    P->top--;
    return de;
}

void filter(struct STACK *P,struct STACK *S)
{
    int temp,count=2,t=P->top+1;
    while(count<=t/2)
    {
      while(S->top!=-1+count)
      {
       push(P,pop(S));
      }
      temp=pop(P);
      while(P->top!=-1+count)
      {
        push(S,pop(P));
      }
      push(S,temp);
    count++;
    }
}

void disp(struct STACK *p)
{
    int i=p->top;
    while(i!=-1)
    {
        printf("%d ",p->items[i]);
        i--;
    }
}
