// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
		int n=nums.size();
        int mini,maxi,ans,x,t;
        mini=maxi=ans=nums[0];
        for(int i=1;i<n;i++)
        {
            x=nums[i];
            t=maxi;
            maxi=max({x,x*mini,x*maxi});
            mini=min({x*mini,x,x*t});
            ans=max(ans,maxi);
            //cout<<maxi<<" - "<<mini<<" + "<<ans<<endl;
        }
        return ans;
    }
};