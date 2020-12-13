class Solution {
public:
  int minCut(string s) {
    const int n = s.length();        
    // dp[i] = min cuts of s[0~i] 
    vector<int>dp(n,n);
    
      
    for (int m = 0; m < n; ++m)      
      for (int d = 0; d <= 1; ++d)
        for (int i = m, j = m + d; i >= 0 && j < n && s[i] == s[j]; --i, ++j)
          dp[j] = min(dp[j], (i ? (dp[i - 1] + 1) : 0));    
    return dp[n - 1];
  }
};
