#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int *a;
int mergesort(int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
#pragma omp task
{
mergesort(low,mid);
}
#pragma omp task 
{
mergesort(mid+1,high);
}
merge(low,mid,high);
}
}
 
int merge(int low,int mid,int high)
{
int i,j,k;
long int b[60000];
i=low;
j=mid+1;
k=low;
while(i<=mid && j<=high)
{
if( a[i] < a[j] )
 {
  b[k]=a[i];
   k++ ; i++ ;
 }
 else
{
 b[k]=a[j];
 k++;j++;
}
while(i<=mid)
{
 b[k]=a[i];
 k++ ; i++ ;
}
while(j<=high)
{
 b[k]=a[j];
 k++ ; j++ ;
}
}
for(i=low;i<k;i++)
{
a[i]=b[i];
}
}
int main()
{
int size;
int i,thread_id;
double start,end;
printf("ente rthe size");
scanf("%d", &size);
a=(int*) calloc(size,sizeof(int));
printf("entered %d elements are\n",size);
omp_set_num_threads(2);
srand(0);
for(i=0;i<size;i++)
{
thread_id=omp_get_thread_num();
a[i]=(rand()%size);
printf("%d\t",a[i]);
}
start=omp_get_wtime();
mergesort(0,size-1);
for(i=0;i<size;i++)
{
printf("thread_id=%d-->a[%d]\n",thread_id,a[i]);
}
end=omp_get_wtime();
printf("sorted array\n");
for(i=0;i<size;i++)
printf("%d\t",a[i]);
printf("\elapsed time =%lf \n", end-start);
}

