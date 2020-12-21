class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    
        unordered_map<int,vector<int>>dict;
      
        
        for(const auto& edge:edges){
            const int f=edge[0];
            const int s=edge[1];
            unordered_set<int>visited;
            if(is_cycle(f,s,dict,visited))
                return {f,s};
            dict[f].push_back(s);
            dict[s].push_back(f);
        }
        
       return {};
    }
private:
    bool is_cycle(int f,int s,const unordered_map<int,vector<int>>& dict,
                  unordered_set<int>&visited)
    {
        if(f==s)return true;
        if(visited.count(f))return false;
        if(!dict.count(f)||!dict.count(s))return false;
        visited.insert(f);
        for(const auto&f_:dict.at(f))
        {
            if(is_cycle(f_,s,dict,visited))
                return true;
        }
        return false;
    }
};
