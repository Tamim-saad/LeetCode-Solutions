class Solution {
public:

int maximize_profit(int n,int arr[])
{
    int i,mid,max_profit=0;

    int minSoFar=arr[0];

    int left_sum=0;
    int right_sum=0;


    for(i=1; i<n; i++)
    {
        if(arr[i]>=minSoFar)
        {
            max_profit=max(max_profit,arr[i]-minSoFar);
        }
        else minSoFar=arr[i];
    }

    return max_profit;
}

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int arr[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=prices[i];
        }
        return maximize_profit(n,arr);
    }
};