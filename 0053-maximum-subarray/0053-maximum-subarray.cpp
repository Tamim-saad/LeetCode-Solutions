class Solution {
public:

    
int largest_subArray_sum(int l,int h,int arr[])
{
    //return case
    if(h<l) return INT_MIN;
    if(h==l) return arr[l];
    if(h-l==1) return max(arr[l]+arr[h],max(arr[l],arr[h]));

    int n,i,mid,maxLeft,maxRight;

    n=h-l+1;
    maxLeft=INT_MIN;
    maxRight=INT_MIN;
    mid=(l+h)/2;

    //divide into left and right part
    int left_largest=largest_subArray_sum(l,mid,arr);      //determine maximum for left subset
    int right_largest=largest_subArray_sum(mid+1,h,arr);   //determine maximum for right subset


    //determine maximum for cross set that starts from left array and ends to right array
    int left_sum=0;
    int right_sum=0;

    for(i=mid; i>=l; i--)
    {
        left_sum+=arr[i];
        maxLeft=max(maxLeft,left_sum);
    }
    for(i=mid+1; i<=h; i++)
    {
        right_sum+=arr[i];
        maxRight=max(maxRight,right_sum);
    }

    //return maximum of left subset, right subset and cross subset
    //cout<<endl<<l<<" "<<mid<<" "<<h<<" "<<left_largest<<" "<<right_largest<<" "<<maxLeft<<" "<<maxRight<<" "<<maxLeft+maxRight<<" ";

    return max(maxLeft+maxRight,max(left_largest,right_largest));
}

    int maxSubArray(vector<int>& arr) {

    int n=arr.size();
    int array[n];
    for(int i=0;i<n;i++)
    {
        array[i]=arr[i];
    }

      int ans=largest_subArray_sum(0,n-1,array);
    return ans;
}

};