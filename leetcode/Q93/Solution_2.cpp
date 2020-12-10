class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12||s.size()<4)return ans;
        const int sz=s.size();
        string curr;
        solve(s,0,curr,sz);
        return ans;
    }
    private:
    vector<string>ans;
    void solve(string s, int index,string curr,const int sz_)
    {
      if(index==4)
          return;
        
          const int sz=s.size();
          
        for(int k=1;k<=3&&k<=sz;k++)
        {
            
            string curr1=curr;
           
            string tmp=s.substr(0,k);
            const int i=stoi(tmp);
            if(to_string(i).size()!=k||i>255)continue;
          
             curr=curr+tmp+(index==3?"":".");
            
              if(sz_==curr.size()-3&&index==3)
                
                 ans.push_back(curr);
              
            solve(s.substr(k),index+1,curr,sz_);
             curr=move(curr1);
            
        }
    }
};
