#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *next;
};
int countNodes(struct node *n)
{
    int res=1;
    struct node *temp=n;
    while(temp->next!=n)
    {
        res++;
        temp=temp->next;
    }
    return res;
}
int countNodesinLoop(struct node *list)
{
    struct node *slow=list,*fast=list;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
            return countNodes(slow);
    }
    return (0);
}
struct node *newNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->next=NULL;
    return temp;
}
int main()
{
    struct node *head=newNode(1);
    head->next=newNode(2);
    head->next->next=newNode(3);
    head->next->next->next=newNode(4);
    head->next->next->next->next=newNode(5);
    head->next->next->next->next->next=head->next;
    printf("%d\n",countNodesinLoop(head));
    return (0);
}
