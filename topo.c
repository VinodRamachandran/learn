#include<stdio.h>
int topo(int adj[80][80],int n);
int main()
{
int adj[80][80],n,i,j;
printf("enter no of nodes");
scanf("%d",&n);
printf("enter tmatrix");
for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
      { 
        scanf("%d",&adj[i][j]);
      }
   }
topo(adj,n);
return;
}
int topo(int adj[80][80],int n)
{
 int sel[10],s[20],u,k=1,top=1,v,i,j,indegree[10] ;

for(j=1;j<=n;j++)
 {
   indegree[j]=0;
   for(i=1;i<=n;i++)
     {
       indegree[j]=indegree[j]+adj[i][j];
     }
}
  for(i=1;i<=n;i++)
    {
      if (indegree[i]==0)
        {
          s[++top]=i;
        }
    }
 while(k<=n)
   {
        u=s[top--];
         sel[k++]=u;
       for(v=1;v<=n;v++)
          {
            if(adj[u][v]==1)
                 {
                   indegree[v]--;    
             if(indegree[v]==0)
               { 
                 s[++top]=v;
                }
           }
      }
 }
printf ("the popped sequence");
for(i=1;i<=n;i++)
 {
   printf ("%d\t",sel[i]);       
  }
}
