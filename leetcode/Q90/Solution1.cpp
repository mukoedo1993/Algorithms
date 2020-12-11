class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       vector<int>curr;
       solve(nums,0,curr); 
        ans.insert(vector<int>());
        return vector<vector<int>>(ans.cbegin(),ans.cend());
    }
    
    private:
    void solve(const vector<int>&nums,int index,vector<int>&curr)
    {
        if(index>nums.size())return;
        ans.insert(vector<int>(curr.cbegin(),curr.cend()));
        for(int i=index;i<nums.size();i++)
        {
            //power set: you need to record the process at each step...
            curr.push_back(nums[i]);
            solve(nums,i+1,curr);
            curr.pop_back();
        }
    }
    set<vector<int>>ans;
 
};
