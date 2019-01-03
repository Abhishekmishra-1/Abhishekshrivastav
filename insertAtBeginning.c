#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *next;
}*head;
void createList(int n);
void insertNodeAtBeginning(int data);
void displayList();
int main()
{
    int data,n;
    printf("Enter total number of nodes:");
    scanf("%d",&n);
    createList(n);
    printf("\n Data in the list \n");
    displayList();
    printf("Enter data to be inserted at the beginning:");
    scanf("%d",&data);
    insertNodeAtBeginning(data);
    printf("\n Data in the list \n");
    displayList();
    return (0);
}
void createList(int n)
{
    struct node *newNode,*temp;
    int data,i;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Unable to allocate memory");
        exit (0);
    }
    else {
        printf("Enter the data of node1:");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
        for(i=2;i<=n;i++)
        {
            newNode=(struct node*)malloc(sizeof(struct node));
            if(newNode==NULL)
            {
                printf("Unable to allocate memory");
                break;
            }
            else {
                printf("Enter the data of node %d:",i);
                scanf("%d",&data);
                newNode->data=data;
                newNode->next=NULL;
                temp->next=newNode;
                temp=temp->next;
            }
        }
        printf("SINGLY LINKED CREATED SUCCESSFULLY \n");
    }
}
void insertNodeAtBeginning(data)
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Unable to allocate memory");
    }
    else {
        newNode->data=data;
        newNode->next=head->next;
        head=newNode;
        printf("DATA INSERTED SUCCESSFULLY \n");
    }
}
void displayList()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else {
        temp=head;
        while(temp!=NULL)
        {
            printf("Data=%d\n",temp->data);
            temp=temp->next;
        }
    }
}
