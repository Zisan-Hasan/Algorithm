#include <stdio.h>

void insertionsort(char a[],int n)
{
   char key;
   int j;
   for(int i=1;i<n;i++){
    key=a[i];
    for(j=i-1;j>=0;j--){
        if(a[j]<key){
            a[j+1]=a[j];
        }
        else{
            break;
        }

    }
    a[j+1]=key;
   }
}

void selectionsort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int max=i;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[max]){
                max=j;
            }
        }
        int temp=a[i];
        a[i]=a[max];
        a[max]=temp;
    }
}

int main()
{
    int n1,n2;
    printf("Enter the number of characters:");
    scanf("%d",&n1);
    char a[n1];
    printf("Enter characters:");
    for(int i=0;i<n1;i++){
        scanf(" %c",&a[i]);
    }
    insertionsort(a,n1);
    printf("After sorting:\n");
    for(int i=0;i<n1;i++){
        printf("%c ",a[i]);
    }

    printf("\n");

    printf("Enter the number of Elements in the array:");
    scanf("%d",&n2);
    int arr[n2];
    printf("Enter the Elements:");
    for(int i=0;i<n2;i++){
        scanf("%d",&arr[i]);
    }

    selectionsort(arr,n2);

    printf("After Sorting:\n");
    for(int i=0;i<n2;i++){
        printf("%d ",arr[i]);
    }
}
