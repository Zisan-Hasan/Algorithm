#include<stdio.h>

void merge(int arr[],int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1],R[n2];


    for(int i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }


    int i=0,j=0,k=left;

    for(;i<n1&&j<n2;k++)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
    }

    for(;i<n1;i++,k++){
        arr[k]=L[i];
    }
    for(;j<n2;j++,k++){
        arr[k]=R[j];
    }
}


void mergesort(int arr[],int n)
{
    int size;
    int start;


    for(size=1;size<=n-1;size=2*size)
    {
        for(start=0;start<n-1;start+=2*size)
        {
            int mid=start+size-1;
            int end=(start+2*size-1<n-1)
                                ? start+2*size-1
                                : n-1;
            if(mid<end){
                merge(arr,start,mid,end);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,n);

    printf("Array after sorting in ascending order:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    printf("\n");
    }


}
