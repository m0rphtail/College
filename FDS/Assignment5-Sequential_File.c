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
	read();
	display();
	return 0;
}

void read()
{
	FILE *p;
	p=fopen("Assignment5.txt", "w");
	printf("Enter name: ");
	scanf("%s", s.name);
	fprintf(p,"%s",s.name);
	fclose(p);
}

void display()
{
	FILE *q;
	q=fopen("Assignment5.txt", "r");
	do
	{
		fscanf(q,"%s",s.name);
		printf("%s", s.name);
	}
	while(!feof(q));
	fclose(q);
}	

