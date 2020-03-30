
//Kshitij Chitnis
//SE-IT
//S2-BATCH
//ROLL NO.8016
//ASSIGNMENT NO.8
//PROBLEM STATEMENT
// Represent a given graph using adjacency matrix/adjacency list and find the shortest path using Dijkstra's algorithm
// (single source all destination).

#include<iostream>
#include<string.h>
#define max 50

using namespace std;

class gnode                            //graphnode class
{
public :
	int vertex;
    gnode * next;
    char name[max];
	gnode()
	{
        next=NULL;
	}
};


class Graph                         //graph class
{
	gnode * list[max];
	int n, adj[max][max];

    void accept();
public :
	Graph()
	{
		accept();
		for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                adj[i][j]=9999;
	}
	~Graph()
	{
	    for(int i=0;i<n;i++)
        {
            delete (list[i]);
           for(int j=0;j<n;j++)
            adj[i][j]=9999;
        }
	}
	void create();
	void display();
	int dijkstra();
	int choose(int[], int, int[]);
	int chk(char[]);
};

int Graph::chk(char sn[])                 //Check function
{
    for(int i=0;i<n;i++)
    {
        if(strcmp(list[i]->name,sn)==0)
        {
            return i;
        }
    }
    return -1;
}
void Graph :: accept()                    //accept function
{
    cout<<"\nEnter no of node in graph : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        list[i]=new gnode;
        list[i]->vertex=i;
        cout<<"\nEnter the place";
        cin>>list[i]->name;
    }
}


void Graph :: create()                 //create function
{
	int i,j,ch;
	char c;
	gnode * ptr;
	char sn[max],en[max];

	cout<<"\n1.Directed graph\n2.Undirected";
	cin>>c;
	do
	{
	    cout<<"\n  Starting place: ";
	    cin>>sn;
	    i=chk(sn);
	    cout<<"\n  Ending place : ";
	    cin>>en;
	    j=chk(en);
	    if(c==2)
	    {
	    cout<<"\n  Weight : ";
	    cin>>adj[i][j];
	    adj[j][i]=adj[i][j];

	    while(adj[i][j]<0)
	    {
	     cout<<"\nNot allowed negative weight";
	     cout<<"\n  Weight : ";
	     cin>>adj[i][j];
	     adj[j][i]=adj[i][j];
	    }
	   }
	  else
          {
            cout<<"\n  Weight : ";
            cin>>adj[i][j];
            while(adj[i][j]<0)
	    {
	     cout<<"\nNot allowed negative weight";
	     cout<<"\n  Weight : ";
	     cin>>adj[i][j];
	    }
          }
            cout<<"\nDo you want to continue (1 for yes and 0 for no) : ";
            cin>>ch;
	}while(ch!=0);
}


void Graph :: display()                //display function
{

	for(int i=0;i<n;i++)
	{
	    cout<<"\n";
		for(int j=0;j<n;j++)
        {
            cout<<"\t"<<adj[i][j];
        }
	}
}

int Graph :: choose(int dist[], int n, int fnd[])                 //choose function for min. position
{
    int min=99999999;
    int i,min_pos=-1;

    for(i=0;i<n;i++)
    {
        if(dist[i] < min && !fnd[i])
        {
            min=dist[i];
            min_pos=i;
        }
    }
    return min_pos;
}

int Graph :: dijkstra()        //function for dijkstra algorithm
{
    int i,j,u=-1,w,found[max];
    int distance[max],pre[max];
    int v,e,ch;
    char sn[max],en[max];

    cout<<"\nEnter starting place";
    cin>>sn;
    v=chk(sn);
    for(i=0;i<n;i++)
    {
        found[i]=0;
        distance[i]=adj[v][i];
        pre[i]=v;
    }

    found[v]=1;
    distance[v]=0;

    for(i=0;i<=n-2;i++)
    {
        cout<<"\n";
        for(int k=0;k<n;k++)

            cout<<" "<<distance[k];
        u=choose(distance,n,found);            //choosing min. distance position
         found[u]=1;
        for(int w=0;w<n;w++)
        {
            if(!found[w])
            {
                if(distance[u]+adj[u][w] < distance[w])
                {
                    distance[w]=distance[u]+adj[u][w];
                    pre[w]=u;
                }
            }
        }

    }
do
 {
  cout<<"\nchoices\n1.All path\n2.single path\n0.cancel";    //displaying all path or particular path
  cin>>ch;
  switch(ch)
   {
   case 1:
    	for(int k=0;k<n;k++)
    	 {
    	    if(k!=v)
    	    {
    	    	cout<<"\n\n  Min distance of node "<<list[k]->name<<" : "<<distance[k];
            	cout<<"\n\n  Path : "<<list[k]->name;
            	int j=k;
            	do
            	{	j=pre[j];
                	cout<<" <- "<<list[j]->name;
            	}while(j!=v);
            }
    	}
    	break;

   case 2:
       	cout<<"\nEnter ending place";
        	        cin>>en;
        	       e=chk(en);
        	        j=e;
        	        cout<<"\n\n  Min distance of node "<<list[j]->name<<" : "<<distance[j];
        	                    	cout<<"\n\n  Path : "<<list[j]->name;

            		do
            		{		j=pre[j];
                  		       cout<<" <- "<<list[j]->name;
                 	}while(j!=v);

        	break;
   case 0:
          break;
      default:cout<<"\nWrong choice";
      break;
     }
    }while(ch!=0);


    cout<<"\n\n  Minimum cost of shortest path : "<<distance[e];
}



int main()
{
	Graph g;
	int ch;

	do
	{
		cout<<"\n\n\t1.  Create\n\t2.  Display\n\t3.  Dijkstra\n\t4.Exit";
		cout<<"\n    Enter choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1 :
				g.create();       //create function call
				break;
			case 2 :
				g.display();      //display function call
				break;
			case 3 :
			    g.dijkstra();         //dijkstra function call
			    break;

            case 4:
                    break;
            default:
                cout<<"\n    INVALID CHOICE ....\n";
                break;
		}
	}while(ch!=4);
}

/*OUTPUT:

Enter no of node in graph : 10

Enter the place USA

Enter the place London

Enter the place Berlin

Enter the place Paris

Enter the place Dubai

Enter the place Moscow

Enter the place Colombia

Enter the place Egypt

Enter the place Madrid

Enter the place Pune


	1.  Create
	2.  Display
	3.  Dijkstra
	4.Exit
    Enter choice : 1

1.Directed graph
2.Undirected1

  Starting place: USA

  Ending place : London

  Weight : 1

Do you want to continue (1 for yes and 0 for no) : 1

  Starting place: Berlin

  Ending place : London

  Weight : 5

Do you want to continue (1 for yes and 0 for no) : 1

  Starting place: USA

  Ending place : Berlin

  Weight : 10

Do you want to continue (1 for yes and 0 for no) : 1

  Starting place: Paris

  Ending place : Berlin

  Weight : 1

Do you want to continue (1 for yes and 0 for no) : 1

  Starting place: Paris

  Ending place : USA

  Weight : 4

Do you want to continue (1 for yes and 0 for no) : 1

  Starting place: London

  Ending place : Colombia

  Weight : 3

Do you want to continue (1 for yes and 0 for no) : 1

  Starting place: Colombia

  Ending place : Dubai

  Weight : 1

Do you want to continue (1 for yes and 0 for no) : 1

  Starting place: Colombia

  Ending place : Moscow

  Weight : 3

Do you want to continue (1 for yes and 0 for no) : 1

  Starting place: Dubai

  Ending place : Moscow

  Weight : 2

Do you want to continue (1 for yes and 0 for no) : 1

  Starting place: Colombia

  Ending place : Egypt

  Weight : 7

Do you want to continue (1 for yes and 0 for no) : 1

  Starting place: Colombia

  Ending place : Madrid

  Weight : 1

Do you want to continue (1 for yes and 0 for no) : 1

  Starting place: Madrid

  Ending place : Pune

  Weight : 2

Do you want to continue (1 for yes and 0 for no) : 1

  Starting place: Pune

  Ending place : Egypt

  Weight : 1

Do you want to continue (1 for yes and 0 for no) : 0


	1.  Create
	2.  Display
	3.  Dijkstra
	4.Exit
    Enter choice : 2

	9999	1	10	9999	9999	9999	9999	9999	9999	9999
	9999	9999	9999	9999	9999	9999	3	9999	9999	9999
	9999	5	9999	9999	9999	9999	9999	9999	9999	9999
	4	9999	1	9999	9999	9999	9999	9999	9999	9999
	9999	9999	9999	9999	9999	2	9999	9999	9999	9999
	9999	9999	9999	9999	9999	9999	9999	9999	9999	9999
	9999	9999	9999	9999	1	3	9999	7	1	9999
	9999	9999	9999	9999	9999	9999	9999	9999	9999	9999
	9999	9999	9999	9999	9999	9999	9999	9999	9999	2
	9999	9999	9999	9999	9999	9999	9999	1	9999	9999

	1.  Create
	2.  Display
	3.  Dijkstra
	4.Exit
    Enter choice : 3

Enter starting place Paris

 4 9999 1 0 9999 9999 9999 9999 9999 9999
 4 6 1 0 9999 9999 9999 9999 9999 9999
 4 5 1 0 9999 9999 9999 9999 9999 9999
 4 5 1 0 9999 9999 8 9999 9999 9999
 4 5 1 0 9 11 8 15 9 9999
 4 5 1 0 9 11 8 15 9 9999
 4 5 1 0 9 11 8 15 9 11
 4 5 1 0 9 11 8 15 9 11
 4 5 1 0 9 11 8 12 9 11
choices
1.All path
2.single path
0.cancel1


  Min distance of node USA : 4

  Path : USA <- Paris

  Min distance of node London : 5

  Path : London <- USA <- Paris

  Min distance of node Berlin : 1

  Path : Berlin <- Paris

  Min distance of node Dubai : 9

  Path : Dubai <- Colombia <- London <- USA <- Paris

  Min distance of node Moscow : 11

  Path : Moscow <- Colombia <- London <- USA <- Paris

  Min distance of node Colombia : 8

  Path : Colombia <- London <- USA <- Paris

  Min distance of node Egypt : 12

  Path : Egypt <- Pune <- Madrid <- Colombia <- London <- USA <- Paris

  Min distance of node Madrid : 9

  Path : Madrid <- Colombia <- London <- USA <- Paris

  Min distance of node Pune : 11

  Path : Pune <- Madrid <- Colombia <- London <- USA <- Paris
choices
1.All path
2.single path
0.cancel2

Enter ending place Egypt


  Min distance of node Egypt : 12

  Path : Egypt <- Pune <- Madrid <- Colombia <- London <- USA <- Paris
choices
1.All path
2.single path
0.cancel0


  Minimum cost of shortest path : 12

	1.  Create
	2.  Display
	3.  Dijkstra
	4.Exit
    Enter choice : 4

*/
