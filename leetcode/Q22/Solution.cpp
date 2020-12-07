//Author: mukoedo1993
//An ugly solution...
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
         string str1(n,'(');const string str2(n,')');
         string str=str1.append(str2);
        do{
            string tmp=str;int cnt=0;
            for(;;cnt++){
            auto indx1=find(tmp.begin(),tmp.end(),'(');
            auto indx2=find(tmp.begin(),tmp.end(),')');
                if(indx1>indx2||indx1==tmp.end())break;
                *indx1='.';tmp.erase(indx2);
               
            }
            if(cnt==n)results.push_back(str);
        }while(next_permutation(str.begin(),str.end()));
       
        return results;
    }
    
   
};
