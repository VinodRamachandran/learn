#include<stdio.h>
int a[50][50],visit[25],vs[10]={0},sum=0,u,last_city=0,ncity,city,cost=0,n;
int mincost(int city)
{
visit[city]=1;
printf("%d-->",city);
ncity=least(city);
if(ncity==999)
{
ncity=0;
printf("%d",ncity);
cost=cost+a[city][ncity];
return;
}
mincost(ncity);
}

int least(int c)
{
int i,min=999,nc=999,kmin;
for(i=0;i<n;i++)
{
if((a[c][i]!=0) && (visit[i]==0))
{
if(a[c][i]<min)
{
min=(a[i][1]+a[c][i]);
kmin=a[c][i];
nc=i;
}
}
}
if(min!=999)
cost=cost+kmin;
return nc;
}

int get()
{
int i,j;
printf("ENTER THE NUMBER OF CITIES\n");
scanf("%d",&n);
printf("enter the distance matrix");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
visit[i]=0;
}
}
return;
}

int put()
{
printf("the min cost is\n");
printf("%d",cost);
}

int nb(int city)
{
int i,j,min,u;
vs[city]=1;
printf("%d-->",city);
u=city;
for(j=0;j<n;j++)
{
min=999;
for(i=0;i<n;i++)
{
if(a[city][i]!=0 && vs[i]==0)
{
if(a[city][i]<min)
{
min=a[city][i];
u=i;
}
}
}
vs[u]=1;
if(min!=999)
{
sum=sum+min;
printf("%d-->",u);
}
city=u;
}
last_city=u;
}

int main()
{
float ratio;
get();
printf("the path is....\n");
mincost(0);
put();
printf("the path is(appro)...\n 0-->");
nb(0);
sum=sum+a[last_city][0];
printf("\nminimum cost is %d\n",sum);
ratio= (float) sum/cost;
printf("\nthe accuracy ratio is %f\n",ratio);
}




