class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int>dict(nums.cbegin(),nums.cend());
        int count=0; const int sz=nums.size();
        
         vector<int>curr;
          vector<bool>index(sz,false);
        solve(curr,index,nums,sz);
         
        return ans;
    }
    private:
    vector<vector<int>>ans;
    void solve( vector<int>&curr,vector<bool>&index,const vector<int>&nums,const int sz)
    {
        if(curr.size()==sz){ans.push_back(curr);return;}
        
        for(int i=0;i<sz;i++){
            if(index[i])continue;
                index[i]=true;
                curr.push_back(nums[i]);
                solve(curr,index,nums,sz);
                //backtracking
                index[i]=false;
                curr.pop_back();
        }
    }
};
