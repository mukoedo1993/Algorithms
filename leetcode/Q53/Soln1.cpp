class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       const int size=nums.size();
        vector<int>dp(size+1);
        
        //dp[i] means the max value that exactly ends at ith element. 
        
        dp[1]=nums[0];
        for(int i=2;i<=size;i++)
        {
            dp[i]=max(dp[i-1]+nums[i-1],nums[i-1]);
            
        }
        return *max_element(dp.cbegin()+1,dp.cend());//max dp[i] for i: 1~size so
        //that we got the soln.
    }
};
