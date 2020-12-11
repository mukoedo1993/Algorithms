template<>
struct hash<vector<int>>{
size_t operator()(const vector<int>&orig)const
{ const int size=orig.size();
   hash<int>h;
   size_t i= h(0);
   for(const auto& it:orig)i^=(h(it));
   return i;
}
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
       sort(candidates.begin(),candidates.end());
        solve(candidates,curr,target,0);
        return(vector<vector<int>>(ans.cbegin(),ans.cend()));
    }
   private:
    unordered_set<vector<int>>ans;
     void solve(const vector<int>&candidates,vector<int>&curr,int target,int index){
        if(target==0){ans.insert(curr); return;}
         if(target<0)return;
         
         for(int indx=index;indx<candidates.size();indx++)
         {
             if(candidates[indx]>target)break;
             curr.push_back(candidates[indx]);
            
             solve(candidates,curr,target-candidates[indx],indx+1);
             curr.pop_back();
         }
    }
    
    
};
