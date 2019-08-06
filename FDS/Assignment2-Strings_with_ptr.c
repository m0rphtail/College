#include<stdio.h>
#include<stdlib.h>
int len(char*s);
void pallin(char*s);
void cmp(char*s,char*p);
void copy(char*s);
void reverse(char*s,char*p);
void subs(char*s,char*p);
int main()
 {
    char *s,*p;
    s=(char*)malloc(sizeof(char)*10);
    p=(char*)malloc(sizeof(char)*10);
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
       
    
case 1:  cmp(s,p);
break;
case 2: copy(s);
break;
case 3:reverse(s,p);
break;
case 4:subs(s,p);
break;
case 5: break;
default: printf("\nEnter valid number");
  }
    }
    return 0;
 
 }
 
int len(char*s) //STRING LENGTH
   { 
     int c=0,i=0;
     while(*(s+i)!='\0')
      { 
       c++;
       i++;
      }
   
     return c;
   } 
 
 void pallin(char*s)  //STRING PALLINDROME
    { 
      int f=0,i=0;
      int l=len(s);
      
      while(i<l/2)
        { 
         if(*(s+i)!=*(s+l-1-i))
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
       
  void cmp(char*s,char*p) //STRING COMPARISON
         { 
           int i,f=0;
            int l=len(s);
       int m=len(p);
      
           
           for(i=0;i<l;i++)
             {  f=0;
            
                   if(*(s+i)!=*(p+i))
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
                
             void copy(char*s) //STRING COPY
       { 
         char *a;
         a=(char*)malloc(sizeof(char)*10);
         int i=0;
          int l=len(s);
           a=s;
          
        
           
            printf("\nCopied string is:%s",a);
          } 
             
             
            
            
           void reverse(char*s,char*p) //STRING REVERSE
             { 
              char *q,*r;
               int l=len(s);
                int m=len(p);
              
              q=(char*)malloc(sizeof(char)*10);
              r=(char*)malloc(sizeof(char)*10);
             
               int i=0;
                int j=0;
                int x=l;
                int y=m;
                
                
                 for(i=0;i<=l;i++)
                  { 
                    *(q+i)=*(s+x-1-i);   
                  
                
                   }
                   
                   printf("\nThe 1st reversed string is: %s ", q);
                   
                   for(j=0;j<=m;j++)
                  { 
                    *(r+j)=*(p+y-1-j);   
                  
                   }
                    printf("\nThe 2nd reversed string is: %s ", r);
                   }
                   
                   
                 void subs(char*s,char*p) //SUBSTRING
                  
                  { 
                  int i=0,j=0,c=0;
                   int l=len(s);
                    int m=len(p);
                 
                  while(*(s+i)!='\0')
                    {
                 
                         while((*(s+i)==*(p+j)) && (*(s+i)!='\0'))
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
                     
