// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int> > dp(m,vector<int>(n));
      // dp[0]={1};

      // for(int k=0; k<n; k++)
      // {
      //   cout<<dp[0][k]=1;//<<" ";
      // }

      
      for(int i=0; i<m;i++)
      {
        for(int j=0; j<n; j++)
        {
          if(!i) dp[i][j]=1;
          else if(!j) dp[i][j]=dp[i-1][j];
          else dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
      }
      return dp[m-1][n-1];
        
    }
};
