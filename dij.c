#include<stdio.h>
int dij(int a[50][50],int source,int n)
{
int distance[50],visit[20],i,j,min,u,v;
for(i=1;i<=n;i++)
{
visit[i]=0;
distance[i]=a[source][i];
}
visit[source]==1;
for(i=1;i<=n;i++)
{
 if(i==source) continue;
 min=999;
 for(j=1;j<=n;j++)
  {
    if(visit[j]==0 & distance[j]<min)
      {
        min=distance[j];
        u=j;
      }
   }
 visit[u]=1;
for(v=1;v<=n;v++)
{
if(visit[v]==0 )
{
if(distance[v]>distance[u]+a[u][v])
  distance[v]=distance[u]+a[u][v];
}
}
}
for(i=1;i<=n;i++)
printf("the distance from source to %d is %d\n",i,distance[i]);
}


int main()
{
int a[50][50],source,i,j,n;
printf("enter n");
scanf("%d",&n);
printf("enter elemnets");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
 }
}
printf("enter the source");
scanf("%d",&source);
dij(a,source,n);
return;
}      
