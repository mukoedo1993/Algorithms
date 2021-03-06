//Author: Huahua
//   https://zxi.mytechroad.com/blog/graph/leetcode-685-redundant-connection-ii/
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    
        vector<int>parents(edges.size()+1,0);
        
        vector<int>ans1;
        vector<int>ans2;
        
        bool dup_parents=false;
        
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            
            //A node has two parents:
            if(parents[v]>0){
                ans1={parents[v],v};
                ans2=edge;
                dup_parents=true;
                
                //Delete the later edge
                edge[0]=edge[1]=-1;
            }
            else{
                parents[v]=u;
            }
        }
        
        //Reset parents
      parents= vector<int>(edges.size()+1,0);
        
        for(const auto& edge:edges){
            int u= edge[0];
            int v=edge[1];
            
            //Invalid edge(we deleted in step 1)
            if(u<0||v<0) continue;
            
            parents[v]=u;
            
            if(cycle(v,parents))
                return dup_parents?ans1:edge;
            //If dup_parents: then the cycle is not damaged even if we
            //deleted the second edge. ans1 and ans2 are double parents.
            //If !dup_parents: then every node has a single parent. v is cyclic point, so
            //we return this edge.
            
        }
        
        return ans2;
        
    }
private:
    bool cycle(int v, const vector<int>&parents)
    {
        int u=parents[v];
        while(u)
        {
            if(u==v)return true;
            u=parents[u];
        }
        return false;
    }

};
