/*............METHOD 1:.........................................*/

// Original Author: Huahua
//https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-132-palindrome-partitioning-ii/
class Solution {
public:
  int minCut(string s) {
    const int n = s.length();
    // valid[i][j] = 1 if s[i~j] is palindrome, otherwise 0
      //default is 1
    vector<vector<int>> valid(n, vector<int>(n, 1));//Use vector<vector<bool>> here will save a lot memory but waste much more time.
    
    //dp[i] minimum cuts of s[0~i]
      vector<int>dp(n,n);
      
      
      //discuss all substring whose length(l) is 2, then 3,.. until n.
      //if valid[i][j] remain unchanged when i>=j. 
      for(int l=2;l<=n;++l)
          for(int i=0,j=l-1;j<n;++i,++j)
             valid[i][j]= ((s[i]==s[j])&&(valid[i+1][j-1]));
      
      
      //if: valid[0][i] then dp[i] is 0
      //else: for each j in[0,i-1], if valid[j+1][i], then dp[i] could be updated with
      //min(dp[j]+1,dp[i]).
      //dp[n-1] is final soln.
      
      
      for(int i=0;i<n;i++){
          if(valid[0][i]){
              dp[i]=0;
              continue;
          }
          for(int j=0;j<i;j++){
              if(valid[j+1][i])
              {  dp[i]=min(dp[i],dp[j]+1);
              
              }
          }
      }
      return dp[n-1];
  }
};
