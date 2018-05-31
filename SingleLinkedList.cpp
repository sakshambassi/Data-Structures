#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node * next;
};

node * create_node(int data)
{
	struct node *temp;
	temp = new(struct node);
	temp->data = data;
	temp->next = NULL;
	return temp;
}

node * insertStart(struct node *head)
{
	int value;
	struct node *temp,*p;
	cout<<"Enter new node's data: ";
	cin>>value;
	temp = create_node(value);
	p = head;
	head = temp;
	head->next = p;
	return head;
}

void display(struct node *head)
{
	struct node *p;
	p=head;
	cout<<"\nThe linked list is: ";
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}

void insertEnd(struct node *head)
{
	int value;
	struct node *p;
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	cout<<"Enter new node's data: ";
	cin>>value;
	p->next = create_node(value);
}

void insertMiddle(struct node *head)
{
	int value;
	struct node *temp, *p, *q;
	p=head;
	cout<<"Enter new node's data: ";
	cin>>value;
	temp = create_node(value);
	cout<<"Enter node's position: ";
	cin>>value;
	while(value!=2)
	{
		p=p->next;
		cout<<"\n----"<<p->data;
		value=value-1;
	}
	cout<<"\n----"<<p->data;
	q = p->next;
	p->next = temp;
	temp -> next = q;
}

node * deleteNode(struct node * head)
{
	int value;
	struct node *p,*q;
	q=head;
	p=q->next;
	cout<<"Enter the node data to be deleted: ";
	cin>>value;
	if(q->data==value)
	{
		cout<<"hw";
		head = p;
		q = NULL;
	}
	else{
		while(p->data!=value)
		{
			p=p->next;
			q=q->next;
		}
		q->next=p->next;
		p=NULL;
	}
	return head;
}

node * reverseList(struct node * head)
{
	struct node *curr, *prev, *next;
	curr = head;
	prev = NULL;
	next = NULL;
	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return head;
}
int main()
{
	int n,value,choice;
	struct node *head, *temp, *p;
	cout<<"\nEnter the number of nodes: ";
	cin>>n;
	cout<<"Enter nodes' data: ";
	cin>>value;
	temp = create_node(value);
	head = temp;
	p = head;
	for(int i=1; i<n; i++)
	{
		cin>>value;
		temp = create_node(value);
		p->next = temp;
		p=p->next;
	}
	p = head;
	cout<<"\nThe linked list is: ";
	for(int i=0; i<n; i++)
	{
		cout<<p->data<<" -> ";
		p=p->next;
	}
	while(1)
	{
		cout<<"\nEnter your choice: ";
		cout<<"\n1. Insert at start\n2. Insert at end\n4. Insert at middle\n4. Delete\n5. Reverse\n6. Exit";
		cin>>choice;
		switch(choice)
		{
			case 1: head = insertStart(head);
					display(head);
					break;
			case 2: insertEnd(head);
					display(head);
					break;
			case 3: insertMiddle(head);
					display(head);
					break;
			case 4: head = deleteNode(head);
					display(head);
					break;
			case 5: head = reverseList(head);
					display(head);
					break;
			case 6: return 0;
		}
	}
	return 0;
}