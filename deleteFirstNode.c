#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *next;
}*head;
void createList(int n);
void deleteFirstNode();
void dispalyList();
int main()
{
    int n,choice;
    printf("Enter total number of nodes:");
    scanf("%d",&n);
    createList(n);
    printf("\n Data in the list \n");
    displayList();
    printf("\n Press 1 to delete first node:");
    scanf("%d",&choice);
    if(choice==1)
        deleteFirstNode();
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
void deleteFirstNode()
{
    struct node *toDelete;
    if(head==NULL)
        printf("List is already empty");
    else {
        toDelete=head;
        head=head->next;
        printf("\n Data deleted=%d\n",toDelete->data);
        free(toDelete);
        printf("Successfully deleted first node from the list\n");
    }
}
void displayList()
{
    struct node *temp;
    if(head==NULL)
        printf("List is empty");
    else {
        temp=head;
        while(temp!=NULL)
        {
            printf("Data=%d\n",temp->data);
            temp=temp->next;
        }
    }
}
