#include<stdio.h>
int max(int a ,int b)
{
if(a>b)
return a;
else
 return b;
}
int knapsack(int n,int m,int p[10],int w[10])
{
int i ,j ,v[60][60],x[10]={0};
for(i=0;i<=n;i++)
{
for(j=0;j<=m;j++)
{
if((i==0) || (j==0))
v[i][j]=0;
else if((j-w[i])<0)
v[i][j]=v[i-1][j];
else
v[i][j]=max(v[i-1][j],p[i]+v[i-1][j-w[i]]);
}
}
printf("the matrix is");
for(i=0;i<=n;i++)
{
for(j=0;j<=m;j++)
{
 printf("%d\t",v[i][j]);
}
printf("\n");
}
printf("the cost is %d",v[n][m]);
j=m;
for(i=n;i>=1;i--)
{
if(v[i][j]!=v[i-1][j])
{
x[i]=1;
j=j-w[i];
}
}
printf("selected items\n");
for(i=1;i<=n;i++)
{
if(x[i]==1)
printf("%d",i);
}
}
int main()
{
int p[10],w[10],m,n,i;
printf("enter n");
scanf("%d",&n);
printf("enter m");
scanf("%d",&m);
printf("enter p");
for(i=1;i<=n;i++)
scanf("%d",&p[i]);
printf("enter w");
for(i=1;i<=n;i++) 
scanf("%d",&w[i]);
knapsack(n,m,p,w);
}

