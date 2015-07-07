#include<stdio.h>
int prims(int n,int a[50][50],int source)
{
int i,visit[10]={0},cost=0,u,p[30],min,k=0,select[10][10],count=0,j;
visit[source]=1;
while(count<(n-1))
{
min=999;
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
{
  if(visit[i]==1 && visit[j]==0)
   {
    if(a[i][j]<min)  
      {
        min=a[i][j];
        u=j;
        p[u]=i;
      }
   }
  }
 }

visit[u]=1;
count++;
select[k][0]=p[u];
select[k][1]=u;
cost=cost+a[u][p[u]];
k++;
}
if(cost<999)
{
printf("the spanning tre exixits\n");
printf("sum is  %d\n", cost);
for(i=0;i<count;i++)
{
printf("%d - %d\n",select[i][0],select[i][1]);
}
}
else 
printf("doesnt exixst");
}
int main()
{
int a[50][50],n,source,i,j;
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
printf("enter source");
scanf("%d",&source);
prims(n,a,source);
}
