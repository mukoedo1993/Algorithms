class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      auto it=find(nums.cbegin(),nums.cend(),target);
        if(it==nums.cend())return{-1,-1};
        auto it1=find(nums.crbegin(),nums.crend(),target);
        if(it1.base()==it+1)
        {
            int i=it-nums.cbegin();
            return {i,i};
        }
        else
        {
            int i=it-nums.cbegin();
            int i1=nums.crend()-it1-1;
            return {i,i1};
        }
        return {};
    }
    };
