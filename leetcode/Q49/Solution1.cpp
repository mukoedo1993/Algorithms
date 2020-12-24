class Solution {
public:
  vector<vector<string>> groupAnagrams(const vector<string>& strs) {
   vector<vector<string>>ans;
      unordered_map<string,vector<int>>m;
      for(int i=0;i<strs.size();i++){
          string s=strs[i];
          sort(s.begin(),s.end());
          (m[s]).push_back(i);
      }
      for(const auto &futari:m){
          ans.push_back({});
          for(int i:m[futari.first])
          {
              ans.back().push_back(strs[i]);
          }
      }
      return ans;
  }
};
