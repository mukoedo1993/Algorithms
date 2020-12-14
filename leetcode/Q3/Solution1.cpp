class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int size=s.size();unordered_set<char>dict;
        if(!size)return 0;
        vector<int>valid(size+1,0);valid[0]=valid[1]=1;
     
       
            for(int i=0;i<size;i++){
                int l;
                for(l=0;l<size-i;l++)
                {
                    if(dict.count(s[i+l]))
                    { valid[l]=1;
                        break;}
                    dict.insert(s[i+l]);
                    
                    
                }
                dict.clear();
                valid[l]=1;
            }
        auto it=   find(valid.crbegin(),valid.crend(),1);
        return distance(it,valid.crend())-1;
        }
        
   
    
 
   
};
