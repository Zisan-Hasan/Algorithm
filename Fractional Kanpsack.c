#include<stdio.h>
float profit[100]={12,10,20,15,5};
float weight[100]={2,1,3,2,1};
float itemfraction[100];

void knapsack(int maxWeight,int n){
    int i;

    for(i=0;i<n-1;i++){
        int max=i;

        for(int j=i+1;j<n;j++){
            if(profit[j]/weight[j]>profit[max]/weight[max]){
                max=j;
            }
        }

        if(max!=i){
            float temp=profit[max];
            profit[max]=profit[i];
            profit[i]=temp;

            float tempo=weight[max];
            weight[max]=weight[i];
            weight[i]=tempo;
        }
    }

    int k;
    float capacity=(float)maxWeight;

    for(int init_k=0; init_k<n; init_k++){
        itemfraction[init_k] = 0.0;
    }

    for(k=0;k<n;k++){
        if(weight[k]>capacity){
            break;
        }
        itemfraction[k]=1.0;

        capacity=capacity-weight[k];
    }

    if (k < n && capacity > 0){
        itemfraction[k]=capacity/weight[k];
    }
}


void profitcalculation(int n){
    float totalprofit=0;
    int i;

    for(i=0;i<n;i++){
        totalprofit+=itemfraction[i]*profit[i];
    }

    printf("Total profit is:%.2f\n",totalprofit);
    for(i=0;i<n;i++){
        printf("Fraction Taken: %.2f\n",profit[i],weight[i],itemfraction[i]);
    }
}


int main()
{

knapsack(5,5);
profitcalculation(5);

}
