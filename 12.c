#include<stdio.h>
#include<math.h>
int k,x[10]={0};
int place(int k ,int x[10])
{
int i;
for(i=0;i<k;i++)
{
if(x[i]==x[k] || abs(i-k)==abs(x[i]-x[k]))
return 0;
}
return 1;
}

int queen(int n)
{
k=1;
while(k!=0)
{
x[k]+=1;
while(x[k]<=n && !place(k,x))
{
x[k]+=1;
}
if(x[k]<=n)
{
if(k==n)
{
printf("soulutionis\n");
for(k=1;k<=n;k++)
printf("%d ..",x[k]);
}
else
{
k++;
x[k]=0;
}
}
else
{
k--;
}
}
}
int main()
{
int n;
printf("enter n");
scanf("%d",&n);
queen(n);
}
