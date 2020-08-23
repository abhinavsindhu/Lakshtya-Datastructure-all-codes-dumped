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
void deletebegin();


void main()
{
    CreateList();
    deletebegin();
    Display();
}
void CreateList()
{
    start=(struct LINK*)malloc(sizeof(struct LINK));
    if(start==NULL)
    {
        printf("Out of memory ");
        exit(1);
    }
        struct LINK *temp;
        temp=start;
        printf("ENTER VALUE ");
        scanf("%d",&temp->info);
        temp->next=NULL;
        printf("DO YOU WANT TO CONTINUE(Y/N) ");
        fflush(stdin);
        char ch;
        scanf("%c",&ch);
        while(ch=='Y')
    {

        temp->next=(struct LINK*)malloc(sizeof(struct LINK));
        if(temp->next==NULL)
        {
           printf("OUT OF MEMORY ");
           exit(1);
        }
        temp=temp->next;
        printf("ENTER VALUE ");
        scanf("%d",&temp->info);
        temp->next=NULL;
        printf("DO YOU WANT TO CONTINUE(Y/N) ");
        fflush(stdin);
        scanf("%c",&ch);
   }
}

void Display()
{
    struct LINK *trav = start;
    while(trav!=NULL)
    {
        printf("%d\n",trav->info);
        trav=trav->next;
    }
}

void deletebegin()
{
    struct LINK *temp=start;
    start=temp->next;
    free(temp);
}
