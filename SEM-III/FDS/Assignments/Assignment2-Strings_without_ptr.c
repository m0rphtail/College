#include<stdio.h>
int len(char[]);
void pallin(char[]);
void cmp(char[],char[],int,int);
void copy(char[],int);
void reverse(char[],char[],int,int);
void subs(char[],char[],int,int);
int main()
 {
    char s[10],p[10];
    int l,m,n=0;
    printf("\nEnter the 1st string: ");
    scanf("%s",s);
    printf("\nThe 1st string is:%s  ",s);
   
   l = len(s);
   printf("\nLength of string is: %d",l);
   pallin(s);
   
    printf("\nEnter the 2nd string: ");
    scanf("%s",p);
    printf("\nThe 2nd string is:%s  ",p);
    m = len(p);
    printf("\nLength of string is: %d",m);
    pallin(p);
    
    while(n!=5)
    {
    printf("  \n1.String Cmp \n2.String Copy \n3.String Reverse \n4.Substring \n5.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&n);
 
    switch(n)
     { 
       
    
 case 1:  cmp(s,p,l,m);
 break;
 case 2: copy(s,l);
 break;
  case 3:reverse(s,p,l,m);
  break;
  case 4:subs(s,p,l,m);
break;
 case 5: break;
 default: printf("\nEnter valid number");
  }
    }
    return 0;
 
 }
 
int len(char s[])
   { 
     int c=0,i=0;
     while(s[i]!='\0')
      { 
       c++;
       i++;
      }
   
     return c;
   } 
   
   
  void pallin(char s[])
    { 
      int f=0,i=0;
      int l=len(s);
      
      while(i<l/2)
        { 
         if(s[i]!=s[l-1-i])
          { 
           f=1;
           break;
          }
         i++;
         } 
         
           if(f==1)
            { 
              printf("\nString is not a pallindrome!");
             }
             
             else
              { 
               printf("\nString is a pallindrome!");
              } 
       }
       
       void cmp(char s[],char p[],int l,int m)
         { 
           int i,f=0;
           for(i=0;i<l;i++)
             {  f=0;
            
                   if(s[i]!=p[i])
                    { 
                      f=1;
                      break;
                     }
                   
                 }
                 
               if(f==1)
                 { 
                   printf("\nString is not same");
                   
          
                 }
                else
                 { 
                   printf("\nString is same");
                  }
                   
                }
     void copy(char s[],int l)
       { 
         char a[10];
         int i=0;
          for(i=0;i<=l;i++)
            { 
             
             a[i]=s[i];
            }
            
            printf("\nCopied string is:%s",a);
          } 
          
        void reverse(char s[],char p[],int l,int m)
             { 
              char q[10],r[10];
       
               int i=0;
                int j=0;
                int x=l;
                int y=m;
                
                
                 for(i=0;i<=l;i++)
                  { 
                    q[i]=s[x-1-i];
                  
                
                   }
                   
                   printf("\nThe 1st reversed string is: %s ", q);
                   
                   for(j=0;j<=m;j++)
                  { 
                    r[j]=p[y-1-j];
                  
                   }
                    printf("\nThe 2nd reversed string is: %s ", r);
                   }
                  
                  
                 void subs(char s[],char p[],int l,int m)
                  
                  { 
                  int i=0,j=0,c=0;
                 
                  while(s[i]!='\0')
                    {
                 
                         while((s[i]==p[j]) && (s[i]!='\0'))
                         {
                          i++;
                          j++;
                          }
                         
                  
                          if (j==m)
                           { 
                           c++;
                       
                           j=0;
                           }
                        
                          else  if(j!=0)
                          {
                           j=0;
                           }
                           else 
                           {
                            i++;
                           
                            j=0;
                            }}
                            
                     printf("Number of times Substring appears %d",c);
                     }       
