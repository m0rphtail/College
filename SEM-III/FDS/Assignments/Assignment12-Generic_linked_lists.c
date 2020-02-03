#include<stdio.h>
#include<stdlib.h>

struct student
{
	int roll;
	char name[20];
	struct student *next;
	struct student *prev;
};

struct student p,*temp,*head=NULL,*temp1,*temp2;
void insert_begin(struct student *temp);
void insert_end(struct student *temp);
void delete_begin();
void delete_end();
void display();

int main()
{
	int choice,i;
	do
	{
		printf("\n1:Insert data at begining \n2:Insert data at End \n3:Display \n4:Delete at begining \n5:Delete at end \n8:exit\n");
		printf("\nEnter the choice:\n");
		scanf("%d",&choice);
		temp=malloc(sizeof(p));
		switch(choice)
		{
			case 1:
				insert_begin(temp);
				break;
				
			case 2:
				insert_end(temp);
				break;
			case 3:
				display();
				break;
			case 4:
				delete_begin();
				break;
			case 5:
				delete_end();
		}
	}while(choice!=8);
	
return 0;
}

void insert_begin(struct student *temp)
{
	printf("Enter the roll number:\n");
	scanf("%d",&temp->roll);
	printf("Enter the name:\n");
	scanf("%s",temp->name);
	if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
		temp->prev=NULL;
	}
	else
	{
		temp->next=head;
		temp->prev=NULL;
		head->prev=temp;
		head=temp;
	}
}

void insert_end(struct student *temp)
{
	printf("Enter the roll number:\n");
	scanf("%d",&temp->roll);
	printf("Enter the name:\n");
	scanf("%s",temp->name);
	if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
		temp->prev=NULL;
	}
	else
	{
		temp1=head;
		while(temp1!=NULL)
		{
			temp2=temp1;
			temp1=temp1->next;
		}
		temp2->next=temp;
		temp->prev=temp2;
		temp->next=NULL;
	}
}

void delete_begin()
{
	temp1=head;
	head=head->next;
	temp2=head;
	printf("Deleted item is %d and %s",temp1->roll,temp1->name);
	free(temp1);
	temp2->prev=NULL;
}

void delete_end()
{
	temp1=head;
	while(temp1->next!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}
	temp2->next=NULL;
	printf("DELETED item %d and name %s\n",temp1->roll,temp1->name);
	free(temp1);
}

void display()
{
	temp1=head;
	while(temp1!=NULL)
	{
		printf("%d %s\n",temp1->roll,temp1->name);
		temp2=temp1; 
		temp1=temp1->next;
	}
	
	printf("\n****REVERSE PRINT*****\n");
	
	while(temp2!=NULL)
	{
		printf("%d %s\n",temp2->roll,temp2->name);
		temp2=temp2->prev;
	}
}
