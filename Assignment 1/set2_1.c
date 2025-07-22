#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void bubblesort(int arr[], int n){
int temp;
for(int i=0;i<n;i++)
{
for (int j=0;j<n;j++)
{
if(arr[j]>arr[j+1]){
temp= arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}
void insertionsort(int arr[], int n){
int key,j;
for( int i=1;i<n;i++){
key=arr[i];
j=i+1;

while(j>=0 && arr[i]>key){
arr[j+1]=arr[j];j--;
}
arr[j+1]=key;
}
}

int main()
{
int n;
printf("Enter number of int:");
scanf("%d",&n);
int *arr=malloc(n *sizeof(int));
if(!arr){
printf("memory failed");
return 1;
}
printf("Enter %d integer \n",n);
for(int i=0;i<n;i++)
scanf("%d",&arr[i]);

pid_t pid=fork();

if (pid==0){
printf("performing insertion...\n");
insertionsort(arr,n);
printf("sorted array:\n");

for(int i=0;i<n;i++)
printf("%d \t",arr[i]);
}
else{

printf("performing bullble sort:\n");
bubblesort(arr,n);
printf("sorted array:\n");

for(int i=0;i<n;i++)
printf("%d \t ",arr[i]);
printf("\n");
}
free(arr);
return 0;
}
