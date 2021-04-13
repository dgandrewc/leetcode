#include<stdio.h>
 
int n, k, arr[100], karr[100], max, idx;
 
int main()
{
    scanf("%d %d", &n, &k);
 
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        max = idx = -1;
        for (int j = 0; j < k; j++)
        {
            if (!karr[j]&&max==-1)
            {
                karr[j] = max = arr[i];
                break;
            }
            if (arr[i] > karr[j])if (max < karr[j])
            {
                idx = j;
                max = karr[j];
            }
        }
        if(idx!=-1)karr[idx] = arr[i];
        if (max==-1)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}
