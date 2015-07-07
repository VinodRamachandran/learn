#include<stdio.h>
int topo(int a[50][50],int n)
{
int i,j,indegree[10],s[10],top=-1,u,v,k=0,select[10];
for(j=0;j<n;j++)
{
indegree[j]=0;
for(i=0;i<n;i++)
{
indegree[j]=indegree[j]+a[i][j];
}
}
for(i=0;i<n;i++)
{
if(indegree[i]==0)
{
s[++top]=i;
}
}
while(k<=n)
{
u=s[top--];
select[k++]=u;
for(v=0;v<n;v++)
{
if(a[u][v]==1)
{
indegree[v]--;
if(indegree[v]==0)
{
s[++top]=v;
}
}
}
}
printf("enter the seq");
for(i=0;i<n;i++)
printf("%d  ",select[i]);
}
int main()
{
int a[50][50],i,j,n;
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
topo(a,n);
}

