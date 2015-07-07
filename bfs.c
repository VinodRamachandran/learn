#include<stdio.h>
#include<stdlib.h>
int q[50],visit[50],adj[50][50];
void bfs(int adj[50][50],int n,int src)
{
int f=0,r=0,v,u;
visit[src]=1;
q[r++]=src;
while(f<r)
{
u=q[f++];
for(v=0;v<n;v++)
{
 if(adj[u][v]==1 && visit[v]==0)
  { visit[v]=1;
    q[r++]=v;
  }
}
}
}
void BFS(int adj[50][50],int n)
{
int src=1,i;
bfs(adj,n,src);
for(i=0;i<n;i++)
{if(visit[i]==1)
  printf("%d is reachable",i);
else 
 printf("%d nt recahable",i);
}
}
int main()
{
int i,j ,n,src;
printf("enter n");
scanf("%d",&n);
printf("ente rmayrix");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&adj[i][j]);
}
}
BFS(adj,n);
}
