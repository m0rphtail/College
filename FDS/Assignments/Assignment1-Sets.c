#include<stdio.h>
void un(int[],int,int[],int);  // function declaration 
void in(int[],int,int[],int);  // function declaration 
void diff(int[],int,int[],int);  // function declaration 
void sdiff(int[],int,int[],int);  // function declaration
int c[50],l,d[50],m;
int main()
 { 
   int a[50],b[50],i,n1,n2,j,x=0;
   printf("\nEnter size of 1st set: ");
   scanf("%d",&n1);
   printf("\nEnter 1st set: ");
    for(i=0;i<n1;i++)
     { 
       
       scanf("%d",&a[i]);
       for(j=0;j<i;j++)
        { 
          if(a[i]==a[j])
           { 
             printf("\nEnter another no. :");
             i--;
             }
             }
       }
       
  /*     printf("\nc array is :");
        for(i=0;i<l;i++)
     {
      printf("\n %d",c[l]);
                 
                   }*/
                   
                   
                   
                   
      
   printf("\nEnter size of 2nd set: ");
   scanf("%d",&n2);
   printf("\nEnter 2nd set: ");
    for(i=0;i<n2;i++)
     {
       scanf("%d",&b[i]);
       for(j=0;j<i;j++)
        { 
          if(b[i]==b[j])
           { 
             printf("\n Enter another no.: ");
             i--;
             }
             }
      }
       while(x!=5)
        {
     
      printf("\n1.Union:");
      printf("\n2.Intersection:");
      printf("\n3.Difference:");
      printf("\n4.Symmetric Difference:");
      printf("\n5.Exit");
       printf("\nEnter your choice:");
      
      scanf("%d",&x);
     
       switch(x)
        {
          
        
      case 1:    un(a,n1,b,n2);  //  function call
       break;
        
     case 2: in(a,n1,b,n2); //  function call
     break;
     case 3: diff(a,n1,b,n2); //function call
     break;
    case 4: sdiff(a,n1,b,n2); //function call
    break;
    case 5:
    
    
     break;
     }}
   
  
    
     return 0;
    
   }
    
   void un(int a[],int n1,int b[], int n2)  //function defination
   
     { 
       int i,j,k=0;
       int f=0,c[50];
       
       for(i=0;i<n1;i++)
         { 
           c[k]=a[i];
           k++;
         }
          
            for(i=0;i<n2;i++) 
             {
               f=0;
                for(j=0;j<n1;j++) 
                 {
                  if(b[i]==a[j])
                   { 
                    f=1;
                  break;
                   }}
                   
                   if(f==0)
                    {
                     c[k]=b[i];
                     k++;
                     }}
                    printf("\nUnion is: ");
                     for(int l=0;l<k;l++)
                    { 
                  printf("\n %d",c[l]);
                   }
              }  
              
            void in(int a[],int n1,int b[], int n2)   //function defination
              {   
              
                 int i,j,k=0;
                 int f=0,d[50];
                 for(i=0;i<n2;i++) 
             {
               f=0;
                for(j=0;j<n1;j++) 
                 {
                  if(b[i]==a[j])
                   { 
                    f=1;
                  break;
                   }}
                   
                   if(f==1)
                    {
                     d[k]=b[i];
                     k++;
                     }}
                     printf("\nIntersection is:");
                     for(int m=0;m<k;m++)
                    { 
                  printf("\n %d",d[m]);
                   }
              }  
                  
                  
                  
              void diff(int a[],int n1,int b[], int n2)  //function defination
              
              
              { 
                int i,j,k=0;
                int f=0,e[50];
                
                
              
                      
                     for(i=0;i<n1;i++) 
                         { f=1;
                          for(j=0;j<n2;j++)
                           {  
                             if(a[i]==b[j])
                               { 
                                f=0;
                                 break;
                                }}
                                
                                if(f==1)
                                  { 
                                   e[k]=a[i];
                                   k++;
                                   }}
                                   
                                   printf("\nDifference is:");
                                    for(int n=0;n<k;n++)
                                     { 
                                     printf("\n %d",e[n]);
                                         }
                    }  
                    
         void sdiff(int a[],int n1,int b[], int n2)  //function defination
                       { 
                          int i,j,k=0;
         int f=0,e[50];
                     for(i=0;i<n1;i++) 
                         { f=1;
                          for(j=0;j<n2;j++)
                           {  
                             if(a[i]==b[j])
                               { 
                                f=0;
                                 break;
                                }}
                                
                                if(f==1)
                                  { 
                                   e[k]=a[i];
                                   k++;
                                   }}
                                   
                                   
                                   
                                   for(j=0;j<n2;j++) 
                            { f=1;
                             for(i=0;i<n1;i++)
                              {  
                               if(a[i]==b[j])
                               { 
                                f=0;
                                 break;
                                }}
                                
                                if(f==1)
                                  { 
                                   e[k]=b[j];
                                   k++;
                                   }}
            
                                   printf("\nSymmetric Difference is:");
                                    for(int n=0;n<k;n++)
                                     { 
                                     printf("\n %d",e[n]);
                                         }
                              
                             
                            }
                          
                            
                 
                                   

