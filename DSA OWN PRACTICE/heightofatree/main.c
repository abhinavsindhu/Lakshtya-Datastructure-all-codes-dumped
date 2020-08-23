#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct QUEUE
{
    int items[50];
    int front;
    int rear;
};

 void Enqueue(struct node *Tr,struct QUEUE *a)
 {
     if(Tr!=NULL)
     {
         a->rear++;
         a->items[a->rear]=Tr->data;
     }

 }
 int Dequeue(struct node *T,struct QUEUE *a)
 {
     int x;
     x=a->items[a->front];
     a->front++;
     return x;
 }
struct node *create()
{
    struct node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);

    if(x==-1)
    {
        return NULL;
    }
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;

    printf("Enter left child of %d:\n",x);
    p->left=create();

    printf("Enter right child of %d:\n",x);
    p->right=create();

    return p;
}
void LevelorderTrav(struct node *t,struct QUEUE *p)
{  int pr;
   p->front=0;
   p->rear=-1;
   Enqueue(t,p);
   while((p->front-1)!=p->rear)
   {
       pr=Dequeue(t,p);
       printf("%d ",pr);
       if(t->left!=NULL)
       Enqueue(t->left,p);
       if(t->right!=NULL)
       Enqueue(t->right,p);
   }

}
void main()
{  struct node *root;
   struct QUEUE s;
   struct QUEUE *p=&s;
    root=create();
    LevelorderTrav(root,p);
}
