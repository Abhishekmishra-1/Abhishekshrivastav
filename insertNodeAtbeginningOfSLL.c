#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
}*head;
void createList(int n);
void insertNodeAtbeginning(int data);
void displayList();
int main()
{
	int n,data;
	printf("Enter total number of nodes: \n");
	scanf("%d",&n);
	createList(n);
	printf("\n Data in the list \n");
	displayList();
	printf("Enter the data to be inserted at the beginning: \n");
	scanf("%d",&data);
	insertNodeAtbegining(data);
	printf("\n Data in the list \n");
	displayList();
	return (0);
}
void createList(int n) {
	struct node *newNode,*temp;
	int data,i;
	head=(struct node*)malloc(sizeof(struct node));
	if(head==NULL) {
	  printf("Unable to allocate memory");
	  exit (0);
	}
	else {
	  printf("Enter the data of node1: \n");
	  scanf("%d",&data);
	  head->data=data;
	  head->next=NULL;
	  temp=head;
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
	      newNode->next=NULL;
	      temp->next=newNode;
	      temp=temp->next;
	    }
	  }
	  printf("\n SINGLY LINKED LIST CREATED SUCCESSFULLY \n");
	}
}
void insertNodeAtbeginning(int data)
{
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	if(newNode==NULL) {
	  printf("List is empty");
	}
	else {
	  newNode->data=data;
	  newNode->next=head;
	  head=newNode;
	}
}
void displayList()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
	  printf("%d\n",temp->data);
	  temp=temp->next;
	}
}
