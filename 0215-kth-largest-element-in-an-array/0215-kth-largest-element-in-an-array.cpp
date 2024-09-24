class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         sort(nums.begin(),nums.end());
     //unique(nums.begin(),nums.end());
     
     int x=0;
     int n=nums.size();
    for(int j=n-1; j>=0; j--)
    { 
        x++;
        if(k==x)
        //cout << arr[j] << " ";
        return nums[j];
        
    }
    return -1;
    }
};