class Solution {
public:
    bool isMatch(string s, string p) {
        const size_t n=s.size(),m=p.size();
        bool dp[n+1][m+1];
        dp[0][0]=true;
        //dp[n][m] means that whether isMatch(s.substr(n),p.substr(m))
        for(size_t i=1;i<=n;i++)
        {
            dp[i][0]=dp[i-1][0]&&(s[i-1]=='*');
        }
         for(size_t i=1;i<=m;i++)
        {
            dp[0][i]=dp[0][i-1]&&(p[i-1]=='*');
        }
        for(size_t i=1;i<=n;i++)
        for(size_t j=1;j<=m;j++)
        { 
            if(s[i-1]=='*'||p[j-1]=='*')
            dp[i][j]= dp[i-1][j]||dp[i-1][j-1]||dp[i][j-1];
            else if(s[i-1]=='?'||p[j-1]=='?')
           dp[i][j]=dp[i-1][j-1];
           else
               dp[i][j]=dp[i-1][j-1]&&(s[i-1]==p[j-1]);
        }
        return dp[n][m] ;
           }
    
    };
