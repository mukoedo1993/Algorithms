//Author: mukoedo1993
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>dict;
        unordered_map<string, char>dict_reverse;
        bool flag=true; const int size=pattern.size();
        istringstream Ob1(s);string str;int i=0;
        while(Ob1>>str){
            if(i==size){return false;}
            const char c=pattern[i];
            const int key1= dict.count(c);
            const int key2=dict_reverse.count(str);
            if(!key1&&!key2)
            { dict[c]=str;
              dict_reverse[str]=c;i++;
             continue;
            }
            
             if( !key1||!key2)
               {flag=false; break;}
            
                if(dict[c]!=str||dict_reverse[str]!=c)
                {  flag=false;break;}
            i++;
        }
       
        return flag&&(i==size);
    }

};
