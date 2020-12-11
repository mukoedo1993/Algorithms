class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
          unordered_set<string>dict(wordList.begin(),wordList.end());
    queue<string>q;
        q.push(beginWord);
        if(!dict.count(endWord)) return 0;
               int l=beginWord.length();
                     int count=0;   
               while(!q.empty()){
                       count++;                                                                                          
                for(int size=q.size();size>0;size--){
                    string s=q.front();
                    q.pop();
                    for(int j=0;j<l;j++){
                        char ch=s[j];
                        for(int k='a';k<='z';k++){
                            s[j]=k;
                            if(endWord==s)return count+1;
                            if(!dict.count(s))continue;
                             dict.erase(s);
                             q.push(s);
                          //  cout<<s<<" "<<'\n';
                        }
                        s[j]=ch;
                    }
                }                                                                                          }
return 0;
    
    }
                                                                                            
  
};
