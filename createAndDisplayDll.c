#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *prev;
struct node *next;
}*head,*last;
void createList(int n);
void displayListFromFirst();
void displayListFromEnd();
int main()
{
    int n,choice;
    head=NULL;
    last=NULL;
    printf("Enter the total number of nodes you want to insert:");
    scanf("%d",&n);
    createList(n);
    printf("\n Press1 to display list from first:");
    printf("\n Press2 to display list from last:");
    scanf("%d",&choice);
    if(choice==1) {
        displayListFromFirst();
    }
    else if(choice==2) {
        displayListFromEnd();
    }
    return (0);
}
void createList(int n)
{
    int data,i;
    struct node *newNode;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL) {
        printf("Unable to allocate memory");
        exit (0);
    }
    else {
        printf("Enter the data of node1:");
        scanf("%d",&data);
        head->data=data;
        head->prev=NULL;
        head->next=NULL;
        last=head;
        for(i=2;i<=n;i++) {
            newNode=(struct node*)malloc(sizeof(struct node));
            if(newNode==NULL) {
             printf("Unable to allocate memory");
             break;
            }
            else {
                printf("Enter the data of node %d:",i);
                scanf("%d",&data);
                newNode->data=data;
                newNode->prev=last;
                newNode->next=NULL;
                last->next=newNode;
                last=newNode;
            }
        }
        printf("Doubly linked list created successfully \n");
    }
}
void displayListFromFirst()
{
    struct node *temp;
    int n=1;
    if(head==NULL) {
        printf("List is empty");
    }
    else {
        temp=head;
        printf("\n\n Data in the list: \n");
        while(temp!=NULL)
        {
            printf("Data=%d\n",n,temp->data);
            n++;
            temp=temp->next;
        }
    }
}
void displayListFromEnd()
{
    struct node *temp;
    int n=0;
    if(last==NULL)
    {
        printf("List is empty");
    }
    else {
        temp=last;
        printf("\n\n Data in the list: \n");
        while(temp!=NULL) {
            printf("Data of last-%d node=%d\n,n,temp->data");
            n++;
            temp=temp->prev;
        }
    }
}
