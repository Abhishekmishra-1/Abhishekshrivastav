#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *next;
}*head;
void createList(int n);
void insertNodeAtMiddle(int data,int position);
void displayList();
int main()
{
    int n,data,position;
    printf("Enter the total number of node:");
    scanf("%d",&n);
    createList(n);
    printf("\n Data in the list \n");
    displayList();
    printf("Enter the data to be inserted at the middle:");
    scanf("%d",&data);
    printf("Enter the position where you want to insert the data:");
    scanf("%d",&position);
    insertNodeAtMiddle(data,position);
    printf("\n Data in the list \n");
    displayList();
    return (0);
}
void createList(int n)
{
    struct node*newNode,*temp;
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
        printf("SINGLY LINJKED LIST CREATED SUCCESSFULLY");
    }
}
void insertNodeAtMiddle(int data,int position)
{
    int i;
    struct node *newNode,*temp;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Unable to allocate memory");
    }
    else {
        newNode->data=data;
        newNode->next=NULL;
        temp=head;
        for(i=2;i<=position-1;i++)
        {
            temp=temp->next;
            if(temp==NULL)
                break;
        }
        if(temp!=NULL)
        {
            newNode->next=temp->next;
            temp->next=newNode;
            printf("Data inserted successfully \n");
        }
        else {
            printf("Unable to insert data at the given position \n");
        }
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
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
