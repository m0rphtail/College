#include<iostream>
#include<string.h>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *top = NULL;

class stack
{
	public:
	struct node * push();
	void pop();
	void display();
};

struct node * stack :: push()
{
	struct Node *temp = new Node;
	cout<<"\nEnter the data: ";
	cin>>temp->data;
	temp->next=top;
	top = temp;	
}

void stack :: pop()
{
	if(top == NULL)
	{
		cout<<"Underflow"<<endl;
		return;
	}
	cout<<top->data<<" is removed."<<endl;
	top = top->next;
}

void stack :: display()
{
	if(top==NULL)
	{
		cout<<"\nList is empty."<<endl;
		return;
	}
	struct Node * temp = top;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\n";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	stack s;
	int ch;
	do{
	
	cout<<"\nENTER CHOICE:\n1.push\n2.pop\n3.display\n0.exit\n:";
	cin>>ch;

	switch(ch)
{
	case 1:
		struct node * head;
		head = s.push();
		break;
	
	case 2:
		s.pop();
		break;

	case 3:
		s.display();
		break;
	
	case 0: 
		break;
}
}
while(ch!=0);
return 0;
}
