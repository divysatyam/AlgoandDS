#include <iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node* link;
	
};
struct node *head=NULL, *rear = NULL;
void insert(int data)
{
	struct node* newnode=new node;
	newnode->data=data;
	newnode->link=head;
	head=newnode;
	if(rear == NULL)
		rear = newnode;

}
void append(int data)
{
	struct node* newnode=new node;
	newnode->data=data;
	// struct node* temp=head;
	// while(temp->link!=NULL)
	// {
	// 	temp=temp->link;
	// }
	// temp->link=newnode;
	newnode->link=NULL;
	rear->link = newnode;
	rear = newnode;
}
void deletenode(int data)
{
	struct node* temp=head;
	struct node* prev;
	while(temp->data!=data)
	{

		prev=temp;
		temp=temp->link;
	} 
	prev->link=temp->link;
	free(temp);
}
void insertatMiddle(int position,int data)
{
	int i=position;
	struct node* temp=head;
	struct node* newnode=new node;
	newnode->data=data;
	while(i!=0)
	{
		temp=temp->link;
		i--;
	}
	newnode->link=temp->link;
	temp->link=newnode;
}
struct node* reverse(struct node* &head) {
	if(head->link == NULL)
		return head;
	struct node* nextToHead = head->link;
	head->link = NULL;
	struct node* newHead = reverse(nextToHead);
	nextToHead->link = head;
	return newHead;
}
void print()
	{
	struct node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
}
int main()
{
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	print();
	cout<<endl;
	deletenode(4);
	print();
	cout<<endl;
	append(6);
	print();
	cout<<endl;
	insertatMiddle(2,7);
	print();
	cout<<endl;
	head = reverse(head);
	print();
	
}
