//Author: mukoedo1993

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int m=grid.size();
        const int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='0')
                    continue;
               
                ++ans;
                dfs(grid,i,j,n,m);
            }
        return ans;
    }
    void dfs(vector<vector<char>>&grid,int i, int j, const int n, const int m)
    {
        grid[i][j]='0';
        if(i<m-1&&grid[i+1][j]=='1')
        {
            dfs(grid,i+1,j,n,m);
        }
        if(j<n-1&&grid[i][j+1]=='1')
        {
            dfs(grid,i,j+1,n,m);
        }
        if(j>0&&grid[i][j-1]=='1')
        {
            dfs(grid,i,j-1,n,m);
        }
        if(i>0 &&grid[i-1][j]=='1')
        {
            dfs(grid,i-1,j,n,m);
        }
        
        
    }
};
