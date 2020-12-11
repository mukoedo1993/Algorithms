class Solution {
public:
    int totalNQueens(int n) {
        vector<int>curr;
        vector<int>row(n);
        vector<int>col(n);
        vector<int>diag1(2*n-1);
        vector<int>diag2(2*n-1);
        ans_=0;
        solve(curr,n,row,col,diag1,diag2);
        
        //return ans.size();
        return ans_;
        
    }
    private:
    //vector<vector<int>>ans;
    int ans_;
    void solve(vector<int>&curr,const int n,vector<int>&row,vector<int>&col,
                  vector<int> &diag1,vector<int>& diag2)
    {
       int sz=curr.size();if(sz==n){
           //ans.push_back(curr);
           ans_++; return;}
       for(int i=0;i<n;i++){
           if(row[i]||col[i]||diag1[i+sz]||diag2[i-sz+n-1])continue;
            row[i]=1;
           col[i]=1;
           diag1[i+sz]=1;
           diag2[i-sz+n-1]=1;
           curr.push_back(i);
           solve(curr,n,row,col,diag1,diag2);
            row[i]=0;
           col[i]=0;
           diag1[i+sz]=0;
           diag2[i-sz+n-1]=0;
           curr.pop_back();
           
       }
        
        
    }
};
