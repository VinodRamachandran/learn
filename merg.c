#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int *a;
int mergesort(int low,int mid ,int high)
{
int i,j,k;
long int b[60000];
i=low;
k=low;
j=mid+1;
while(i<=mid && j<=high)
{
if(a[i]<a[j])
{
b[k]=a[i];
i++;k++;
}
else
{
b[k]=a[j];
k++;j++;
}
} 
while(i<=mid)
{
b[k]=a[i];
i++;k++;
}
while(j<=high)
{
b[k]=a[j];
j++;k++;
}
for(i=low;i<k;i++)
{
a[i]=b[i];
}
}
int merge(int low,int high)
{
int mid;
if(low<high)
{
mid=(high+low)/2;
#pragma omp task
merge(low,mid);
#pragma omp task
merge(mid+1,high);
mergesort(low,mid,high);
}
}
int main()
{
int size,i,thread_id;
double end,start;
printf("enter size");
scanf("%d",&size);
a=(int *)calloc(size , sizeof(int));
printf("selected array is");
omp_set_num_threads(2);
srand(0);
for(i=0;i<size;i++)
{
thread_id=omp_get_thread_num();
a[i]=(rand()%size);
printf("%d\t",a[i]);
}
start=omp_get_wtime();
merge(0,size-1);
for(i=0;i<size;i++)
{
printf("\n thread_id=%d--> a[%d]",thread_id,a[i]);
}
end=omp_get_wtime();
printf("sorted array is");
for(i=0;i<size;i++)
printf("%d\t",a[i]);
printf("\ntime is %lf\n",end-start);
}



