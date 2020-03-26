//Kshitij chitnis
//SE-IT
//S2-Batch
//ROLL NO.8016
//ASSIGNMENT :7

// PROBLEM STATEMENT
// Represent any real world graph using adjacency list/adjacency matrix find minimum spanning tree using Kruskal’s algorithm

#include<iostream>
#include<string.h>
#define max 50

using namespace std;

class gnode              //graphnode class
{
public:
    gnode *next;
    char name[max];
    gnode()
    {
        next=NULL;
    }
};

class edge              //edge class
{
public:
    gnode *st,*et;
    int wght;
    edge()
    {
        st=et=NULL;
    }
};
class graph          //graph class
{
    gnode *g[max];
    edge *elst[max];
    int edg,n;
    int cost[max][max];
public:

graph()              //constructor
    {
        cout<<"\nEnter the number of places Present in graph: ";
        cin>>n;
        edg=0;
        for(int i=0;i<n;i++)
        {
            g[i]=new gnode;
            //g[i]->vno=i;
            cout<<"\nEnter the place: ";
            cin>>g[i]->name;

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cost[i][j]=99999;
            }
        }
    }
 ~graph()
  {
      dealloc();
  }
    void accept();
    void display();
    void krs();
    void sort();
    int chk(char[]);
    int check(int[],int,int);
    void dealloc();
};

void graph::dealloc()
{
    for(int i=0;i<n;i++)
        {
          delete(g[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cost[i][j]=99999;
            }
        }
}
int graph::chk(char sn[])            //check function
{
    for(int i=0;i<n;i++)
    {
        if(strcmp(sn,g[i]->name)==0)
        {
            return i;
        }
    }
    return -1;
}
void graph::accept()               //accept function
{
    char sn[max],en[max];
    int s,e;
    char ch;

  do{
        cout<<"\nEnter the starting place: ";
        cin>>sn;
        s=chk(sn);
        while(s<0||s>=n)
        {
            cout<<"\nReenter the correct starting place: ";
            cin>>sn;
            s=chk(sn);
        }

        cout<<"\nEnter the Ending place: ";
        cin>>en;
        e=chk(en);
        while(e<0||e>=n||e==s)
        {
            cout<<"\nReenter the correct Ending place: ";
            cin>>en;
            e=chk(en);
        }

        if(cost[s][e]==99999)
        {
            cout<<"\nEnter the weight: ";
            cin>>cost[s][e];
            while(cost[s][e]<=0)
            {
                cout<<"\nWeight cannot be 0 or negative...Reenter";
                cin>>cost[s][e];
            }
            cost[e][s]=cost[s][e];
        elst[edg]=new edge;
        elst[edg]->st=g[s];
        elst[edg]->et=g[e];
        elst[edg]->wght=cost[s][e];
        edg++;
        sort();

        elst[edg]=new edge;
        elst[edg]->st=g[e];
        elst[edg]->et=g[s];
        elst[edg]->wght=cost[e][s];
        edg++;
        sort();

        }
        else
        {
            cout<<"\nDistance is already Entered ";
        }
        cout<<"\nDo you want to continue? (y/n): ";
        cin>>ch;
  }while(ch=='y' || ch=='Y');

}

void graph :: sort()              //sort function
{
    edge * t1, * t2;
    int i=0;
    t1=elst[edg-1];
    while( i < edg && elst[i]->wght <= t1->wght)
    {
        i++;
    }
    while(i != edg)
    {
        t2=elst[i];
        elst[i]=t1;
        t1=t2;
        i++;
    }
}

void graph::display()           //display function
{
    int ch;

    do
    {

      cout<<"\n1.Adj matrix\n2.Edges display\n3.Exit\n";
      cin>>ch;
    switch(ch)
    {
    case 1:
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<" "<<cost[i][j];
                }
                cout<<endl;
            }
            break;
    case 2:
            for(int i=0;i<edg;i++)
            {
                cout<<"\n"<<i+1<<")"<<elst[i]->st->name;
                cout<<"->"<<elst[i]->et->name;
                cout<<" = "<<elst[i]->wght;
            }
            break;
    case 3:
            break;
      default:cout<<"\n invalid choice 3 to exit";
      break;
    }
 }while(ch!=3);
}

void graph::krs()               //kruskal algorithm's function
{
    int i, s, e, visited[max],loop[max];
    int tc=0, no_edges=1, flag=0, flag2=0;
    edge * spanning[max];

    for(i=0;i<n;i++)
    {
        visited[i]=0;
        loop[i]=i;
    }
    i=-1;
    if(n==0)
    {
        flag2=1;
    }
    while(no_edges < n)
    {
        i++;
        s=chk(elst[i]->st->name);
        e=chk(elst[i]->et->name);

        flag=check(loop,s,e);
        if(flag==1)
        {
                visited[s]=1;
                visited[e]=1;
                spanning[no_edges-1]=elst[i];
                tc=tc+elst[i]->wght;
                no_edges++;
        }
    }
    if(flag2==0)
    {
        cout<<"\n  Edges of MST: ";
        for(i=0; i<n-1; i++)
        {
            cout<<"\n  "<<i+1<<". "<<spanning[i]->st->name;
            cout<<" -> "<<spanning[i]->et->name;
        }
        cout<<"\n  Cost of minimum spanning tree : "<<tc;
    }
    else
        cout<<"\n Graph is empty....";
}

int graph :: check(int loop[], int s, int e)     //loop check function
{
    int stn,endn,i;
    stn=loop[s];
    endn=loop[e];
    if(stn!=endn)
    {

        for(i=0;i<n;i++)
        {
            if(loop[i]==endn)
            {
                loop[i]=stn;
            }
        }
         return 1;
    }
    return 0;
}

int main()
{
    graph g;

    int ch;

    do
    {
        cout<<"\n1.Accept\n2.Display\n3.MST Kruskal\n4.EXIT";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
                g.accept();    //accept function call
                break;
        case 2:
                g.display();   //display function call
                break;
        case 3:
                g.krs();      //kruskal mst function call
                break;
        }
    }while(ch!=4);
}



/*OUTPUT:

Enter the number of places Present in graph: 3

Enter the place: USA

Enter the place: UK

Enter the place: India

1.Accept
2.Display
3.MST Kruskal
4.EXIT
Enter your choice: 1

Enter the starting place: USA

Enter the Ending place: India

Enter the weight: 100

Do you want to continue? (y/n): y

Enter the starting place: UK

Enter the Ending place: India

Enter the weight: 50

Do you want to continue? (y/n): y

Enter the starting place: USA

Enter the Ending place: UK

Enter the weight: 50

Do you want to continue? (y/n): n

1.Accept
2.Display
3.MST Kruskal
4.EXIT
Enter your choice: 2

1.Adj matrix
2.Edges display
3.Exit
1

 99999 50 100
 50 99999 50
 100 50 99999

1.Adj matrix
2.Edges display
3.Exit
2

1)UK->India = 50
2)India->UK = 50
3)USA->UK = 50
4)UK->USA = 50
5)USA->India = 100
6)India->USA = 100

1.Adj matrix
2.Edges display
3.Exit
3

1.Accept
2.Display
3.MST Kruskal
4.EXIT
Enter your choice: 3

  Edges of MST: 
  1. UK -> India
  2. USA -> UK
  Cost of minimum spanning tree : 100

1.Accept
2.Display
3.MST Kruskal
4.EXIT

Enter your choice: 4

*/
