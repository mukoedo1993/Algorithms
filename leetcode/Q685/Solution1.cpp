

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
     
        vector<int>parents(edges.size()+1);
        vector<int>roots(edges.size()+1);
        vector<int>sizes(edges.size()+1,1);
        
        vector<int>ans1;
        vector<int>ans2;
        
        
        for(auto& edge:edges){
            const int u=edge[0];
            const int v=edge[1];
            
            //A node has two parents
            if(parents[v]>0)
            {
                ans1={parents[v],v};
                ans2=edge;
                
                //delete the later edge
                edge[0]=edge[1]=-1;
            }
            
            parents[v]=u;//u->v
        }
            for(const auto&edge: edges){
                
                int u=edge[0];
                int v=edge[1];
                
                //Invalid edge (we deleted it in step1)
                if(u<0||v<0)continue;
                
                if(!roots[u])roots[u]=u;
                if(!roots[v])roots[v]=v;
                int pu=find(u,roots);
                int pv=find(v,roots);
                
                //Both u and v are both in the tree
                if(pu==pv)
                    return ans1.empty()?edge:ans1;
                //If ans1 is empty, then for each node, there is only a single parent.
                //It is a question equivalent to the previous one, which has no direction.
                //So, we return the edge we are traversing currently...
                //Otherwise, the edge is an edge which is a child for double parents. 
                //And, this edge is a part of the circle...
                
                //Union, always merge smaller set (pv) to larger set (pu)
                if(sizes[pv]>sizes[pu])
                    swap(pv,pu);
                
                roots[pv]=pu;
                sizes[pu]+=sizes[pv];
            }
        
                return ans2;
        //In this case, obviously, there is a node which has double parents... 
        // the edge which is a part of circle is destroyed. We need to return the destroyed edge.
        }
    private:
                int find(int node, vector<int>& roots){
                    while(roots[node]!=node){
                        roots[node]=roots[roots[node]];
                        node=roots[node];
                    }
                    return node;
                }
    };
