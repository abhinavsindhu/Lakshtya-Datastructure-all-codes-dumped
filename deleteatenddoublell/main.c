#include <stdio.h>
#include <stdlib.h>
struct dlink
{
    struct dlink *prev;
    int info;
    struct dlink *next;
};
struct dlink *start;
void createlist();
void display();
void deletatend();
int main()
{
    createlist();
    deleteatend();
    display();
    return 0;
}
void createlist()
{
    start=(struct dlink*)malloc(sizeof(struct dlink));
    if(start==NULL)
    {
        printf("OUT OF MEMEORY...");
        exit(1);
    }
    struct dlink *temp=start;
    printf("ENTER VALUE FOR NODE :");
    scanf("%d",&temp->info);
    temp->prev=NULL;//ONLY ONE NODE PRESENT IN DOUBLE LL.SO PREV AND NEXT BOTH PART WILL BE NULL>
    temp->next=NULL;//
    char ch;
    printf("DO YOU WANT TO CONTINUE(y/n)");
    fflush(stdin);
    scanf("%c",&ch);
    struct dlink *curr;
    while(ch=='y')
    {
        curr=(struct dlink*)malloc(sizeof(struct dlink));
        if(curr==NULL)
        {
            printf("OUT OF MEMEORY");
            exit(1);
        }
        temp->next=curr;
        curr->prev=temp;
        temp=temp->next;
        printf("ENTER VALUE FOR NODE\n");
        scanf("%d",&temp->info);
        temp->next=NULL;
        printf("DO YOU WANT TO CONTINUE(y/n)");
        fflush(stdin);
        scanf("%c",&ch);
    }
}
void display()
{
  struct dlink *temp,*last;
  temp=start;
  printf("\nFORWARD DISPLAY\n");
  /*while(temp!=NULL)
  {
      printf("%d ",temp->info);
      last=temp;
      temp=temp->next;
  }
  */
  while(temp!=NULL)
  {
      printf("%d ",temp->info);
      if(temp->next==NULL)
        break;
      temp=temp->next;
  }
  printf("\n BACKWARD DISPLAY\n");
  /*while(last!=NULL)
  {
      printf("%d ",last->info);
      last=last->prev;
  }
  */
  /*while(last!=NULL)
  {
      printf("%d ",last->info);
      last=last->prev;
  }
  */
  while(temp!=NULL)
  {
      printf("%d ",temp->info);
      temp=temp->prev;
  }

}

void deleteatend()
{

   struct dlink *temp=start;
   while(temp->next!=NULL)
   {

      temp=temp->next;
   }
   temp->prev->next=NULL;
   free(temp);

}

