/*Implement sequential file and perform following operations: 
i. Display 
ii. Add records 
iii. Search record 
iv. Modify record 
v. Delete record */

#include<stdio.h>

struct student
{
	char name[50],grade;
	int roll_no,marks;
}s;

void read();
//void add();
//void search();
//void modify();
//void delete();
void display();

int main()
{
	//FILE *x;
	//x=fopen()
	read();
	display();
	return 0;
}

void read()
{
	FILE *p;
	p=fopen("Assignment5.txt", "w");
	if(p==NULL)
	{
		printf("File failed to open!");
	}
	else
	{
		printf("Enter name: ");
		scanf("%s", s.name);
		printf("Enter roll number: ");
		scanf("%d", &s.roll_no);
		fprintf(p,"%s",s.name,s.roll_no);
		fclose(p);
	}
}

void display()
{
	FILE *q;
	if((q=fopen("Assignment5.txt", "r"))==NULL)
	{
	printf("NULL");
	}
	else{
	do
	{
		fscanf(q,"%s %d",s.name, s.roll_no);
		printf("%s %d", s.name, s.roll_no);
	}
	while(!feof(q));
	}
	fclose(q);
}	

