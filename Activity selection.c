#include<stdio.h>

void sort(int f[100],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(f[i]>f[i+1])
        {
// int temp=f[i];
// f[i]=f[i+1];
// f[i+1]=f[i];
            int temp = f[i];
            f[i] = f[i+1];
            f[i+1] = temp;

        }
    }
}

void printfmaxactivities(int s[],int f[],int n)
{
    int i=0,count=1;
    int j=1;
    printf("%d ",s[i],f[i]);
    for(j=1; j<=n; j++)
    {
        if(s[j]>=f[i])
        {
            count++;
            printf("%d ",s[j],f[j]);
            i=j;
        }
    }
    printf("\n");
    printf("%d",count);


}

int main()
{
    int s[100]= {1,0,5,3,5,3,12,2,8,8,6};
    int f[100]= {4,6,7,8,9,5,14,13,12,11,10};
    int n=11;
    sort(f,n);
    sort(s,n);
    int i,j;
    for(i=0; i<n; i++)
    {
        printf("%d ",s[i]);

    }

    printf("\n");
    for(j=0; j<n; j++)
    {

        printf("%d ",f[j]);
    }
    printf("\n");
    printfmaxactivities(s,f,n);
}
