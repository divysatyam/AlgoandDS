#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
	int data;
	struct node* prev;
	struct node* next;
};

void insert(struct node* &head, struct node* &last,int data)
{
	struct node* newnode=new node;
	newnode->data=data;
	if(head==NULL)
	{
		head=newnode;
		newnode->prev=NULL;
		newnode->next=NULL;
		last=head;
	}
	else
	{
		newnode->next=head;
		newnode->prev=NULL;
		head->prev=newnode;
		head=newnode;
	}


}
void reverseprint(struct node* head)
{
	struct node* temp=head;
	if(temp->next != NULL)
	{
		reverseprint(temp->next);
	}
	cout<<temp->data<<" ";


}
void append(struct node* &head, struct node* &last,int data)
{
	struct node* newnode=new node;
	newnode->data=data;
	if(head==NULL)
	{
		head=newnode;
		newnode->prev=NULL;
		newnode->next=NULL;
		last=head;
	}
	else
	{
		last->next=newnode;
		newnode->prev=last;
		newnode->next=NULL;
		last=newnode;

	}

}
void insertAtMiddle(struct node* &head,struct node* &last,int key,int data)
{
	struct node* temp=head;
	struct node* newnode=new node;
	newnode->data=data;
	while(temp!=NULL&&temp->data!=key)
	{
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<key<<" is not present in the list"<<endl;
		return;
	}
	if(temp->next==NULL)
	{
		append(head,last,data);
		return;
	}
	
	else
	{
		newnode->next=temp->next;
		newnode->prev=temp;
		temp->next->prev=newnode;
		temp->next=newnode;

	}
}
void deletefirst(struct node* &head)
{
	if(head==NULL)
	{
		cout<<"List is empty/n";
		return;
	}
	if(head->next==NULL)
	{
		free(head);
		return;
	}

	struct node* temp=head;
	head->next->prev=NULL;
	head=head->next;
	free(temp);
	
}
void deletelast(struct node* &last)
{
	if(last==NULL)
	{
		cout<<"List is empty/n";
	}
	struct node* temp=last;
	last->prev->next=NULL;
	last=last->prev;
	free(temp);

}
void deleteatMiddle(struct node* &head,int key)
{
	struct node* temp=head;
	struct node* prev;
	while(temp!=NULL&&temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		cout<<key<<" is not present in the list/n";
	}
	prev->next=temp->next;
	temp->next->prev=prev;
	temp->next=temp->prev=NULL;
	free(temp);

}
void print(struct node* &head)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

void freelist(struct node* &head) {
	struct node* temp = head->next;
	while(temp) {
		head->next = temp->next;
		free(temp);
		temp = head->next;
	}
	free(head);
}
int main()
{
	int ch,data,prevdata,key;
	struct node* head=NULL;
	struct node* last=NULL;
	while(1) {
		cout<<"1. Insert 2. InsertAtMiddle 3. Append 4. Print 5.deletefirst 6.deletelast 7.reverse print 8.deleteatMiddle 9.exit\n";
		cin>>ch;
		switch(ch) {
			case 1: cin>>data;
					insert(head,last,data);
					break;
			case 2: cin>>prevdata>>data;
					insertAtMiddle(head,last,prevdata,data);
					break;
			case 3: cin>>data;
					append(head,last,data);
					break;
			case 4: print(head);
					cout<<endl;
					break;
			case 5: deletefirst(head);
					break;
			case 6: deletelast(last);
					break;
			case 7:reverseprint(head);
					cout<<endl;
					break;
			case 8:	cin>>key;
					deleteatMiddle(head,key);
		}
		if(ch == 9) {
			break;
		}
	}
	freelist(head);

}
