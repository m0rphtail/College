/*Implement sequential file and perform following operations: 
i. Display 
ii. Add records 
iii. Search record 
iv. Modify record 
v. Delete record */

#include<stdio.h>

struct student
{
	char name[50],grade[5];
	int roll_no,marks;
}s;

void read();
void add();
void search();
void modify();
void delete();
void display();
void exit();

int main()
{
	int c;
	char l;
	FILE *x;
	x=fopen("Assignment5.txt", "w");
	fprintf(x,"");
	fclose(x);
	a:
	printf("\n\nSelect an option\n1. Add Data\n2. Search Data\n3. Modify Data\n4. Delete Data\n5. Display Data\n6. Exit\nEnter your choice: ");
	scanf("%d", &c);
	printf("\n");
	switch(c)
	{
		case 1:read();
		break;
		case 2:search();
		break;
		case 3:modify();
		break;
		case 4:delete();
		break;
		case 5:display();
		break;
		case 6:exit(1);
		break;
		default:printf("Invalid choice!");
		break;
	}
	printf("\nDo you want to continue? (y/n) : ");
	scanf("%s",&l);
	if(l=='y')
	{
		goto a;
	}
	else
	{
		exit(1);
	}
	return 0;
}

void read()
{
	FILE *p;
	p=fopen("Assignment5.txt", "a");
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
		printf("Enter marks: ");
		scanf("%d",&s.marks);
		printf("Enter grade: ");
		scanf("%s", s.grade);
		fprintf(p,"%s %d %d %s",s.name, s.roll_no, s.marks, s.grade);
		fclose(p);
	}
}

void add()
{
	read();
}

void search()
{

}

void modify()
{

}

void delete()
{

}

void display()
{
	FILE *q;
	if((q=fopen("Assignment5.txt", "r"))==NULL)
	{
		printf("File empty!");
	}
	else
	{
		do
		{
			fscanf(q,"%s %d %d %s",s.name, &s.roll_no, &s.marks, s.grade);
			printf("\n\nName: %s \nRoll No: %d \nMarks: %d \nGrade: %s", s.name, s.roll_no, s.marks, s.grade);
		}
		while(!feof(q));
	}
	fclose(q);
}

	

