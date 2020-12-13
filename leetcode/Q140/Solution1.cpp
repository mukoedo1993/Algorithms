class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string>dict(wordDict.cbegin(),wordDict.cend());
        dict.insert("");
        return wordBreak(s,dict);
    }
private:
    bool wordBreak(const string&s, const unordered_set<string>& dict){
        
       
        if(mem_.count(s))return mem_[s];
        
        if(dict.count(s))return mem_[s]=true;
        
        for(int i=1;i<s.size();i++){
            const string left=s.substr(0,i);
            const string right=s.substr(i);
            if(dict.count(right) &&wordBreak(left,dict))
               return mem_[s]=true;
        }
        return mem_[s]=false;
    }
    
    unordered_map<string,bool>mem_;
};
