
// Author: mukoedo1993
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    auto futari=equal_range(nums.cbegin(),nums.cend(),target);
      if(futari.first==nums.cend()||*(futari.first)!=target)
          return{-1,-1};
      else if(futari.second==futari.first+1)
      {
          int firstLoc=futari.first-nums.cbegin();
         return {firstLoc,firstLoc};
      }
      else{
          int firstLoc= futari.first-nums.cbegin();
          int secondLoc= futari.second-futari.first+firstLoc-1;
          return {firstLoc,secondLoc};
      }
      
  }

    
};
