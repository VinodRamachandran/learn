#include<stdio.h>
int visit[30],n,a[50][50];
int dfs(int u)
{
int v;
for(v=0;v<n;v++)
{
if(a[u][v]==1 && visit[v]==0)
{
visit[v]=1;
dfs(v);
}
}
}
int main()
{
int i,j,source;
printf("enter n");
scanf("%d",&n);
printf("enter elements");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
  scanf("%d",&a[i][j]);
}
}
source=0;
visit[source]=1;
dfs(source);
for(i=0;i<n;i++)
{
if(visit[i]==0)
{
printf("graph nt connected");
return;
}
}
printf("graph connected");
return;
}


