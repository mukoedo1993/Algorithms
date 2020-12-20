//O(n.log star n) approxi. O(n)
//Original author: Huahua
class UnionFindSet{
    public:
    UnionFindSet(const int n):ranks_(n+1),parents_(n+1){
     
        for(int i=0; i<n+1;++i)
          parents_[i]=i;
    }
    
    //Merge sets that contain u and v
    //Return true if merged, false if u and v are already in one set.
    bool Union(int u, int v){
        int pu=Find(u);
        int pv=Find(v);
        if(pu==pv)
            return false;
        
        //Merge low rank tree into high rank tree
        if(ranks_[pv]>ranks_[pu])
             parents_[pu]=pv;
        else if(ranks_[pu]>ranks_[pv])
            parents_[pv]=pu;
        else
        {
            parents_[pv]=pu;
            ranks_[pv]+=1;
        }
        return true;
    }
  private:  
    int Find(int u){
        //compress the path during traversal
        if(u!=parents_[u])
            parents_[u]=Find(parents_[u]);
           return parents_[u];
    }
   
    vector<int>parents_;
    vector<int>ranks_;
};

class Solution {
public:
    
    vector<int> findRedundantConnection(const vector<vector<int>>& edges) {
        UnionFindSet s(edges.size());
        
         for(const auto& edge:edges){
             if(!s.Union(edge[0],edge[1]))
                 return edge;
         }
        return {};
    }
};
