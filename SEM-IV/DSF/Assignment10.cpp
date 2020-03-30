//Kshitij Chitnis
//SE-IT
//S2-BATCH
//ROLL NO.8016

//ASSIGNMENT 10
// PROBLEM STATEMENT
// A business house has several offices in different countries. They want to lease phone lines to connect them with each
// other and the phone company charges different rent to connect different pairs of cities. Business house want to connect
// all its offices with a minimum total cost. Solve the problem by suggesting appropriate data structures.
//

#include<iostream>
#include<string.h>
#define max 50

using namespace std;

class gnode         //graphnode class
{
public :
	char country[max];
	int dist;
    gnode * next;

	gnode()
	{
        next=NULL;
        dist=0;
	}
};

class Graph     //Graph class
{
    gnode * list[max];
	int n;

    void accept();
    int chk(int, int);
    int search(char[]);
    int min(gnode *);
public :
	Graph()
	{
		accept();

	}
	~Graph()
	{
	    for(int i=0;i<n;i++)
        {
            delete(list[i]);
        }
	}
	void create();
	void display();
	void prims();

};

void Graph :: accept()    //accept function
{
    cout<<"\nEnter no of offices in several countries : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        list[i]=new gnode;

        cout<<"\n  Enter country name : ";
        cin>>list[i]->country;
    }
}

void Graph :: create()   //create function
{
	char c1[max], c2[max];
	int s,e,d,ch;
	gnode * ptr;

	do
	{
	    cout<<"\n  Enter the src country name:- ";
	    cin>>c1;
	    s=search(c1);
	    while(s==-1)
        {
            cout<<"\n  Please enter correct name....";
            cout<<"\n  Enter the src country name:- ";
            cin>>c1;
            s=search(c1);
        }
	    cout<<"\n  Enter dest country name:- ";
	    cin>>c2;
	    e=search(c2);
	    while(e==-1)
        {
            cout<<"\n  Please enter correct name....";
            cout<<"\n  Enter dest country name:- ";
            cin>>c2;
            e=search(c2);
        }

        if(chk(s,e)==1)
        {
            cout<<"\n  Distance from "<<c1<<" to "<<c2<<" : ";
            cin>>d;
            while(d < 0)
            {
                cout<<"\n Negative distances not allowed";
                cout<<"\n  Please enter correct distance : ";
                cin>>d;
            }

            ptr=new gnode;
            strcpy(ptr->country,list[e]->country);
            ptr->dist=d;

            ptr->next=list[s]->next;
            list[s]->next=ptr;

            ptr=new gnode;
            strcpy(ptr->country,list[s]->country);
            ptr->dist=d;

            ptr->next=list[e]->next;
            list[e]->next=ptr;
        }
        else
            cout<<"\n "<<c1<<" to "<<c2<<" distance is already entered by user....\n";

        cout<<"\nDo you want to continue (1 for yes else 0) : ";
		cin>>ch;

	}while(ch!=0);
}

int Graph :: chk(int i, int j)    //check function
{
    gnode * ptr;
    int k;
    ptr=list[i]->next;
    while(ptr!=NULL)
    {
        k=search(ptr->country);
        if(k==j)
            return 0;
        ptr=ptr->next;
    }
    return 1;
}

int Graph :: search(char n1[max])   //search function
{
	for(int i=0; i<n; i++)
	{
		if(strcmp(list[i]->country,n1)==0)
			return i;
	}
	return -1;
}

void Graph :: display()        //display function
{
	gnode * ptr;

	for(int i=0;i<n;i++)
	{
		ptr=list[i];
		cout<<"\n  ";
		while(ptr!=NULL)
		{
		    if(ptr!=list[i])
                cout<<ptr->dist<<"\t->\t";
			cout<<ptr->country;

			if(ptr->next!=NULL)
				cout<<"\t->\t";
			ptr=ptr->next;
		}
	}

}

void Graph :: prims()    //prims algo. function
{
    int v, i, k, no_edges, tc=0, visited[max];
    int st[max], end[max], c=0,min;
    gnode * ptr;

    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    if(n==0)
        cout<<"\n  Graph is empty...";
    else
    {
        v=search(list[0]->country);
        visited[v]=1;
        no_edges=1;

        while(no_edges < n)
        {
            //i=min(list[v]);
            min=99999999;
            for(i=0;i<n;i++)
            {
              if(visited[i]==1)
              {
                    ptr=list[i]->next;
                while(ptr!=NULL)
                {
                    k=search(ptr->country);
                    if(ptr->dist < min && visited[k]==0)
                    {
                        min=ptr->dist;
                        v=k;
                        st[c]=i;
                    }
                    ptr=ptr->next;
                }
              }
            }
            end[c]=v;
            c++;
            visited[v]=1;
            tc=tc+min;
            no_edges++;
        }

        for(i=0;i<c;i++)
            cout<<"\n "<<list[st[i]]->country<<" -> "<<list[end[i]]->country;
        cout<<"\n  Minimum total cost of spanning tree : "<<tc;
    }
}

int main()
{
	Graph g;
	int ch;

	do
	{
		cout<<"\n\n\t1.  Create\n\t2.  Display\n\t3.  Prims\n\t4.  Exit";
		cout<<"\n    Enter choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1 :
				g.create();   //create function call
				break;
			case 2 :
				g.display();  //display function call
				break;
			case 3 :
			    g.prims();        //prims function call
			    break;
            case 4 :
                break;
            default:
                cout<<"\n    INVALID CHOICE ....\n";
                break;
		}
	}while(ch!=4);
}


/*OUTPUT:

Enter no of offices in several countries : 6

  Enter country name : America

  Enter country name : Europe

  Enter country name : Asia

  Enter country name : Africa

  Enter country name : Russia

  Enter country name : Antarctica


	1.  Create
	2.  Display
	3.  Prims
	4.  Exit
    Enter choice : 1

  Enter the src country name:- America

  Enter dest country name:- Europe

  Distance from America to Europe : 1

Do you want to continue (1 for yes else 0) : 1

  Enter the src country name:- Europe

  Enter dest country name:- Asia

  Distance from Europe to Asia : 10

Do you want to continue (1 for yes else 0) : 1

  Enter the src country name:- Asia

  Enter dest country name:- Africa

  Distance from Asia to Africa : 9

Do you want to continue (1 for yes else 0) : 1

  Enter the src country name:- Africa

  Enter dest country name:- Russia

  Distance from Africa to Russia : 8

Do you want to continue (1 for yes else 0) : 1

  Enter the src country name:- Russia

  Enter dest country name:- Antarctica

  Distance from Russia to Antarctica : 2

Do you want to continue (1 for yes else 0) : 1

  Enter the src country name:- Antarctica

  Enter dest country name:- America

  Distance from Antarctica to America : 6

Do you want to continue (1 for yes else 0) : 1

  Enter the src country name:- Europe

  Enter dest country name:- Africa

  Distance from Europe to Africa : 4

Do you want to continue (1 for yes else 0) : 1

  Enter the src country name:- Europe

  Enter dest country name:- Russia

  Distance from Europe to Russia : 7

Do you want to continue (1 for yes else 0) : 0


	1.  Create
	2.  Display
	3.  Prims
	4.  Exit
    Enter choice : 2

  America	->	6	->	Antarctica	->	1	->	Europe
  Europe	->	7	->	Russia	->	4	->	Africa	->	10	->	Asia	->	1	->	America
  Asia	->	9	->	Africa	->	10	->	Europe
  Africa	->	4	->	Europe	->	8	->	Russia	->	9	->	Asia
  Russia	->	7	->	Europe	->	2	->	Antarctica	->	8	->	Africa
  Antarctica	->	6	->	America	->	2	->	Russia

	1.  Create
	2.  Display
	3.  Prims
	4.  Exit
    Enter choice : 3

 America -> Europe
 Europe -> Africa
 America -> Antarctica
 Antarctica -> Russia
 Africa -> Asia
  Minimum total cost of spanning tree : 22

	1.  Create
	2.  Display
	3.  Prims
	4.  Exit
    Enter choice : 4
 
*/
