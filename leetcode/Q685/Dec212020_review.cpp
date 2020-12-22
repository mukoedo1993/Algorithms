class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
         vector<int> parents(edges.size()+1);
         
        vector<int>ans1;
        vector<int>ans2;
        bool dup_parents=false;
        for(auto &edge: edges)
        {
            const int f=edge[0];
            const int s=edge[1];
            if(!parents[s])
            {
                parents[s]=f;
            }
            else
            {
                ans1={parents[s],s};
                ans2=edge;
                edge[0]=-1;
                edge[1]=-1;
                dup_parents=true;
            }
        }
        for(int& i:parents)i=0;
       
        for(const auto&edge:edges)
        {
            const int f=edge[0];
            const int s=edge[1];
            if(f<0||s<0)
                continue;
            parents[s]=f;
            if(is_cycle(f,parents))
                return dup_parents?ans1:edge;
            
        }
        return ans2;
    }
    
private:
    bool is_cycle(int f, const vector<int>& parents){
        int s=parents[f];
        while(s)
        {
            if(s==f)return true;
            s=parents[s];
        }
        return false;
    }
};
