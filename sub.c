#include<stdio.h>
int x[10]={0},w[20],k,m,n;
int subset(int sumf,int k,int remain)
{
int i;
x[k]=1;
if(sumf+w[k]==m)
{
printf("the weights selected are\n");
for(i=0;i<n;i++)
{
if(x[i]==1)
printf("%d",w[i]);
}
}
else if(sumf+w[k]+w[k+1]<=m)
{
subset(sumf+w[k],k+1,remain-w[k]);
}
if(sumf+(remain-w[k])>=m && sumf+w[k]<=m)
{
x[k]=0;
subset(sumf,k+1,remain-w[k]);
}
}
int main()
{
int sumf,k,remain,sum=0,i;
printf("enter the no. of elemnts\n ");
scanf("%d",&n);
printf("the witghts\n");
for(i=0;i<n;i++)
scanf("%d",&w[i]);
printf("capacity\n");
scanf("%d",&m);
for(i=0;i<n;i++)
sum=sum+w[i];
if(sum<m || w[0]>m)
printf("solution doesnt exist ");
else
subset(0,0,sum);
return;
}
