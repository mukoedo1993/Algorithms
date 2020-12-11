class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
       solve(n,1,k,curr);
        return soln;
    }
    private:
    vector<vector<int>>soln;
     void solve(int n,int indx, int k,vector<int>&curr){
         if(curr.size()==k){
             soln.emplace_back(curr.cbegin(),curr.cend());
            return;               
         }
         for(int i1=indx;i1<=n;i1++)
         {
            
             curr.push_back(i1);
             solve(n,i1+1,k,curr);
             curr.pop_back();
         }
       
     }
    
};

//time complexity: O(C(n,k))
//space complexity: O(n)
