#include<stdio.h>
#include<time.h>
int qsort(int a[2000],int low,int high)
{
int s;
if(low<=high)
{
s=partition(a,low,high);
qsort(a,low,s-1);
qsort(a,s+1,high);
}
}
int partition(int a[2000],int low,int high)
{
int pivot,i,j,temp;
pivot=a[low],
i=low;
j=high+1;
while(i<=j)
{ 
  do{ i++; }
 while (pivot>=a[i]);
  do{ j-- ;}
 while( pivot <a[j]);
 if(i<j)
  {
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
  }
 temp=a[low];
 a[low]=a[j];
 a[j]=temp;
}
return j;
}
int main()
{
int a[2000],low,high,i,n,ch;
float start ,end,time;
printf("no of elements");
scanf("%d",&n);
low=0;
high=n-1;
printf("enter 1. n<10 2. N>100 ");
scanf("%d",&ch);
switch(ch)
{
case 1 :
printf("array elemners");
for(i=0;i<n;i++)
{
 scanf("%d",&a[i]);
}
qsort(a,low,high);
printf("the sorted array is ");
for(i=0;i<n;i++)
{
printf("%d",a[i]);
}
break ;
case 2 :
for(i=0;i<n;i++)
a[i]=rand()%20;
start=clock();
for(i=0;i<=1000;i++)
{
qsort(a,low,high);
}
end=clock();
printf("the soretd array is ");
for(i=0;i<n;i++)
{
 printf("%d",a[i]);
}
time=(end-start)/ CLOCKS_PER_SEC;
printf("time elsapse id %f",time);
break;
}
}

