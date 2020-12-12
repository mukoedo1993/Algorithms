//Author: mukoedo1993

class Solution {
public:
    vector<vector<string>> partition(string s) {
        const int size=s.size();
        //size>=1 AND size<=16:
        //trivial case:
        if(size==1)return{{s}};
        //general case:
        vector<vector<string>>ans;vector<string>curr;
       
            solve(s,0,curr,size,size,ans);
        return ans;
    }
    private:
    vector<vector<string>>ans;
    
    void solve(const string&s,const int index,vector<string>&curr,
               const int size,const int remain,
              vector<vector<string>>&ans)
    {
        if(remain<0)return;
        if(remain==0){
            ans.push_back(curr); return;}
        for(int i=index;i<size;i++){
            if(!is_valid(s,index,i-index+1))continue;
            
            curr.push_back(s.substr(index,i-index+1));

            
        solve(s,i+1,curr,size,remain-i+index-1,ans);
            curr.pop_back();
        }
    }
    
    bool 
    constexpr
    is_valid(const string&s,const int index,const int length){
         
        return(length<=1?true: (s[index]==s[length+index-1])&&is_valid(s,index+1,length-2));
        
    }

    
};
