#include <stdio.h>
#include <string.h>

#define MAX 50

int convert(int t)
{
    int hour, min;

    if (t < 100)
    {
        hour = t;
        min = 0;
    }
    else if (t < 1000)
    {
        hour = t / 100;
        min = t % 100;
    }
    else
    {
        hour = t / 100;
        min = t % 100;
    }

    if (min >= 60) min = 0;
    return hour * 60 + min;
}

int auto_time(int s, int f)
{
    s = convert(s);
    f = convert(f);
    if (f <= s) f += 24 * 60;
    return f;
}

void print_time(int t)
{
    int hour = (t / 60) % 24;
    int min  = t % 60;
    printf("%02d:%02d", hour, min);
}

int main()
{
    int n, i, j;
    int start[MAX], finish[MAX];
    char name[MAX][50];
    int selected[MAX];

    printf("Enter number of scenes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nScene %d name: ", i+1);
        scanf("%s", name[i]);
        printf("Start time : ");
        scanf("%d", &start[i]);
        printf("Finish time : ");
        scanf("%d", &finish[i]);
        finish[i] = auto_time(start[i], finish[i]);
        start[i] = convert(start[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(finish[j] > finish[j+1])
            {
                int ts = start[j];
                start[j] = start[j+1];
                start[j+1] = ts;

                int tf = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = tf;

                char temp[50];
                strcpy(temp, name[j]);
                strcpy(name[j], name[j+1]);
                strcpy(name[j+1], temp);
            }
        }
    }

    int count = 0;
int lastFinish = -1;

for(i = 0; i < n; i++)
{
    if(start[i] >= lastFinish)
    {
        selected[count++] = i;
        lastFinish = finish[i];
    }
}

    printf("\nSelected Scenes:\n");
    for(i = 0; i < count; i++)
    {
        int idx = selected[i];
        printf("%s Start: ", name[idx]);
        print_time(start[idx]);
        printf(" Finish: ");
        print_time(finish[idx]);
        printf("\n");
    }
    printf("Total Selected Scenes: %d\n\n", count);

    int items, capacity;
    int weight[MAX], value[MAX];
    int dp[100][100];
    int chosen[MAX];

    printf("Enter number of equipment items: ");
    scanf("%d", &items);

    for(i = 1; i <= items; i++)
    {
        printf("Item %d weight: ", i);
        scanf("%d", &weight[i]);
        printf("Item %d value: ", i);
        scanf("%d", &value[i]);
    }

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    for(i = 0; i <= items; i++)
    {
        for(j = 0; j <= capacity; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(weight[i] <= j)
            {
                int v1 = dp[i-1][j];
                int v2 = value[i] + dp[i-1][j-weight[i]];
                dp[i][j] = (v1 > v2) ? v1 : v2;
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int maxValue = dp[items][capacity];
    int k = 0;
    int w = capacity;

    for(i = items; i >= 1; i--)
    {
        if(dp[i][w] != dp[i-1][w])
        {
            chosen[k++] = i;
            w -= weight[i];
        }
    }

    printf("\nSelected Equipment:\n");
    if(k == 0)
    {
        printf("None\n");
    }
    else
    {
        for(i = k - 1; i >= 0; i--)
        {
            int it = chosen[i];
            printf("Item %d Weight: %d Value: %d\n", it, weight[it], value[it]);
        }
    }

    printf("Total Production Value: %d\n", maxValue);

}
