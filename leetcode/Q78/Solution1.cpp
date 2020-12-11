class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int n=nums.size();
         vector<int>curr;
         
          sort(nums.begin(),nums.end());
        solve(nums,curr,n,0);
        ans_.insert(vector<int>());
        return(vector<vector<int>>(ans_.cbegin(),ans_.cend()));
    }
    private:
    void solve(const vector<int>& nums,vector<int>&curr, int n,int index)
    {    
        if(index>n)return;
        ans_.insert(vector<int>(curr.cbegin(),curr.cend()));
        for(int i=index;i<n;i++){
           
            
            curr.push_back(nums[i]);
            solve(nums,curr,n,i+1);
            curr.pop_back();
          
        }
    }
    set<vector<int>>ans_;
};
