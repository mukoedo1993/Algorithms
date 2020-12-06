class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //http://www.cplusplus.com/reference/algorithm/next_permutation/
        vector<vector<string>>rslt;
        const vector<string>v_str;
       vector<int>v_i(n,0);
        for(int i=0;i<n;i++)v_i[i]=i;
        //permutation
        do{
            if(is_exist(v_i,n))
            {
                rslt.emplace_back(v_str);
                for(int i=0;i<n;i++)
                {   rslt.back().emplace_back(n,'.');
                    rslt.back().back()[v_i[i]]='Q';
                }
                    
            }
                
        }
        while(next_permutation(v_i.begin(),v_i.end()));//header file: algorithm
        return rslt;
        
    }
 private:   
    bool 
        constexpr
        is_exist(const vector<int>& orig,const int sz)
{
    for(int i=0;i<sz;i++)
        for(int j=i+1;j<sz;j++)
        {if(abs(orig[i]-orig[j])==(j-i))
                return false;}
    return true;
    
}
};
