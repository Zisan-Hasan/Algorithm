 #include<stdio.h>
#include<stdlib.h>
int count=0;
int partition(int arr[],int start,int end)
{

    int i=start-1;
    int pindex=start+rand()%(end-start+1);
    int x=arr[pindex];
    arr[pindex]=arr[end];
    arr[end]=x;
    int pivot=arr[end];

    printf("%d \n",pivot);
    for(int j=start;j<end;j++){
            count++;
        if(arr[j]<pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[end];
    arr[end]=temp;

    return i+1;

}

void quicksort(int arr[],int start,int end)
{
   if(start<end){
    int x=partition(arr,start,end);
    quicksort(arr,start,x-1);
    quicksort(arr,x+1,end);

   }

}

int main()
{
    int n;
    printf("Enter the size of an array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Pivot:\n");



    quicksort(arr,0,n-1);
    printf("After Sorting\n");

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }



    printf("\nNubmer of comparisn:%d",count);

}
