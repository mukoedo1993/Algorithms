//Make the M const reference:
//It will use the memory more efficiently.
class Solution {
public:
    int findCircleNum(const vector<vector<int>>& M) {
       if(M.empty())return 0;
        const int n=M.size();
        vector<int>visited(n);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(visited[i])continue;
            dfs(M,i,n,visited);
            ++ans;
        }
        return ans;
}
private:
    void dfs(const vector<vector<int>>&M, int curr, int n,
             vector<int>& visited){
          if(visited[curr])return;
           visited[curr]=1;
           for(int i=0;i<n;++i){
               if(M[curr][i]&&!visited[i])
               dfs(M,i,n,visited);
           }
        }
        
    
};
