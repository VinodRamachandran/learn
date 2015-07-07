#include<stdio.h>
#include<stdlib.h>
int visit[10];
int BF(int a[50][50],int n)
{
int i,source;
source=1;
bfs(a,n,source);
for(i=1;i<=n;i++)
{
if(visit[i]==1)
printf("%d is recahable",i);
else
printf("%d is nt recahbale",i);
}
}
int bfs(int a[50][50],int n,int source)
{
int r=0,f=0,q[20],u,v;
visit[source]=1;
q[r++]=source;
while(f<r)
{
u=q[f++];
for(v=1;v<=n;v++)
{
if(a[u][v]==1 && visit[v]==0)
{
visit[v]=1;
q[r++]=v;
}
}
}
}
int main()
{
int i,j,n,a[50][50];
printf("enter n");
scanf("%d",&n);
printf("enter elements");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
  scanf("%d",&a[i][j]);
}
}
BF(a,n);
}
