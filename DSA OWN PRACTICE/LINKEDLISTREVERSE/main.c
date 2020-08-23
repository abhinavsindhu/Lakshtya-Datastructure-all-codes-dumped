#include <stdio.h>
#include <stdlib.h>
struct LINK
{
    int info;
    struct LINK *next;
};
struct LINK *head;
void CreateList();
void Display();
void Reverse();
void main()
{
    CreateList();
    Display();
    Reverse();
    printf("\n");
    Display();
}
void CreateList()
{
    head=(struct LINK*)malloc(sizeof(struct LINK));
    struct LINK *temp=head;
    if(head==NULL)
    {
        printf("OUT OF MEMORY\n");
        exit(1);
    }
    temp->next=NULL;
    printf("ENTER DATA INTO THE NODE\n");
    scanf("%d",&temp->info);
    char ch;
    printf("DO YOU WANT TO CONTINUE\n");
    fflush(stdin);
    scanf("%c",&ch);
    while(ch=='Y')
    {
        temp->next=(struct LINK*)malloc(sizeof(struct LINK));
        if(temp->next==NULL)
        {
           printf("OUT OF MEMORY\n");
           exit(1);
        }
        temp=temp->next;
        temp->next=NULL;
        printf("ENTER DATA INTO THE NODE\n");
        scanf("%d",&temp->info);
        printf("DO YOU WANT TO CONTINUE(Y/N)\n");
        fflush(stdin);
        scanf("%c",&ch);
    }


}
void Display()
{
    struct LINK *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp=temp->next;
    }
}
void Reverse()
{
    struct LINK *Curr,*Prev,*Next;
    Curr=head;
    Prev=Next=NULL;
    while(Curr!=NULL)
    {
        Next=Curr->next;
        Curr->next=Prev;
        Prev=Curr;
        Curr=Next;
    }
    head=Prev;
}
