//origin: Huahua
//modified by:mukoedo1993
//use cbegin rather than begin, crbegin rather than cend if possible.
//use conatiner<T>::at() rather than operator[] if possible.
//So, it could be easier for us to find out the potential errors.

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.cbegin(),wordList.cend());
        if(!dict.count(endWord))return{};
        
        dict.erase(beginWord);
        
        dict.erase(endWord);
        if(dict.size()==0)return {};
        queue<string>q;q.push(beginWord);
       
        //initialization:
        //To prevent from the edgy cases:
        //endWord must be founded in the unordered_map parents as a key value.
        
        unordered_map<string,int>steps{{beginWord,1}};
        unordered_map<string,vector<string>>parents{{endWord,{}}};
        
        
      
        const int size=endWord.size();
         bool found=false;
         int  step=0;
        
        while(!q.empty()&&!found){
            step++;
            const  int sz=q.size();
            for(int i0=0;i0<sz;i0++){
            const string s=q.front();
            q.pop();
            string w=s;
            for(int i=0;i<size;i++){
                const char ch=s[i];
                for(int j='a';j<='z';j++)
                {
                    if(j==ch)continue;
                    w[i]=j;
                    
                    if(w==endWord){
                        parents[w].push_back(s);
                        //cout<<w<<" "<<s<<endl;
                        found=true;
                    }
                    else{
                        if(steps.count(w)&&step<steps.at(w))
                           
                        { parents[w].push_back(s);
                           //cout<<w<<endl;
                        }
                    }
                    
                    if(!dict.count(w))continue;
                    dict.erase(w);
                    //cout<<w<<" "<<step<<endl;
                    steps[w]=step+1;
                    parents[w].push_back(s);
                    q.push(w);
                    
                }
                w[i]=ch;
            }
          }
        }
        vector<vector<string>>ans;
        vector<string>curr;
        solve(beginWord,endWord,ans,curr,parents);
        return ans;
    }
   void solve(const string& beginWord,
              const string& endWord,
              vector<vector<string>>& ans,
              vector<string>& curr,
               const unordered_map<string,vector<string>>&parents)
   {
       
       if(endWord==beginWord){
           curr.push_back(endWord);
           ans.push_back(vector<string>(curr.crbegin(),curr.crend()));
           curr.pop_back();
           return;
       }
        
       for(const string &str:( parents.at(endWord))){
           curr.push_back(endWord);
           solve(beginWord,str,ans,curr,parents);
           curr.pop_back();  
       }
   }
    
};
