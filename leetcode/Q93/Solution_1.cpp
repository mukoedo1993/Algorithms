class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        const int sz=s.size();
        if(sz<4||sz>12)return ans;
        
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            for(int k=1;k<=3;k++)
                for(int l=1;l<=3;l++)
            {
               if(i+j+k+l==sz)
               {
                   int i1=stoi(s.substr(0,i));
                   if(to_string(i1).size()!=i||i1>255)continue;
                   int i2=stoi(s.substr(i,j));
                   if((to_string(i2)).size()!=j||i2>255)continue;
                   int i3=stoi(s.substr(i+j,k));
                   if(to_string(i3).size()!=k||i3>255)continue;
                   int i4=stoi(s.substr(i+j+k));
                   if(to_string(i4).size()!=l||i4>255)continue;
                   ans.push_back(s.substr(0,i)+"."+s.substr(i,j)
                            + "." +s.substr(i+j,k)+"."+ s.substr(i+j+k) );
               }
            }
        return ans;
    }
    private:
    vector<string>ans;
};
