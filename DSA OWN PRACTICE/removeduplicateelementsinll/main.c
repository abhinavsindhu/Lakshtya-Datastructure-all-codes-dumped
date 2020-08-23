#include <stdio.h>
#include <stdlib.h>
struct LINK
{
    int info;
    struct LINK *next;
};
struct LINK *start;//global pointer

void CreateList();
void Display();
void removedupl();
void main()
{
    CreateList();
    printf("YOU ENTERED THIS LLINKED LIST\n");
    Display();
    removedupl();
    printf("AFTER REMOVING DUPLICATE NODE IN LINKED LIST\n");
    Display();
}
void CreateList()
{
    start=(struct LINK*)malloc(sizeof(struct LINK));
    if(start==NULL)
    {
        printf("Out of memory");
        exit(1);
    }
        struct LINK *temp;
        temp=start;
        printf("ENTER VALUE  :");
        scanf("%d",&temp->info);
        temp->next=NULL;
        printf("DO YOU WANT TO CONTINUE(Y/N)  :");
        fflush(stdin);
        char ch;
        scanf("%c",&ch);
        while(ch=='Y')
    {

        temp->next=(struct LINK*)malloc(sizeof(struct LINK));
        if(temp->next==NULL)
        {
           printf("OUT OF MEMORY");
           exit(1);
        }
        temp=temp->next;
        printf("ENTER VALUE  :");
        scanf("%d",&temp->info);
        temp->next=NULL;
        printf("DO YOU WANT TO CONTINUE(Y/N)  :");
        fflush(stdin);
        scanf("%c",&ch);
   }
}

void Display()
{
    struct LINK *trav = start;
    while(trav!=NULL)
    {
        printf("%d ",trav->info);
        trav=trav->next;
    }
}

void removedupl()
{
   struct LINK *ptr1,*ptr2,*de;
   ptr1=start;
   while(ptr1!=NULL && ptr1->next!=NULL)
   {
       ptr2=ptr1;
       printf("ptr1->info=%d AND ptr2->info=%d ",ptr1->info,ptr2->next->info);
       while(ptr2->next!=NULL)
       {
           if(ptr1->info==ptr2->next->info)
           {
               de=ptr2->next;
               ptr2->next=ptr2->next->next;
               free(de);
           }
           else
            ptr2=ptr2->next;
       }
       ptr1=ptr1->next;
   }
}
