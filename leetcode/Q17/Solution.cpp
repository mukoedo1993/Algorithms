class Solution {//bfs: breadth-first search
//author: huahua modified by:mukoedo1993
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return vector<string>();
        unordered_map<char,string>mp1;
        mp1.insert({'2',"abc"});
        mp1.insert({'3',"def"});
        mp1.insert({'4',"ghi"});
        mp1.insert({'5',"jkl"});
        mp1.insert({'6',"mno"});
        mp1.insert({'7',"pqrs"});
        mp1.insert({'8',"tuv"});
        mp1.insert({'9',"wxyz"});
        
        
      rslts={""};
      for(char digit:digits){//fix the digit at each time
         vector<string>tmp;// use tmp to collect strings
          for(const string&str: rslts ){
            for(char c:mp1[digit])  {
                tmp.push_back(str+c);//update tmp with each string
            }
            
          }
          tmp.swap(rslts);//update rslts after all elements of rslts have been updated with c at
          //this time.
      }   
           
          
    
      return rslts;
    }
    private:
    vector<string>rslts;
};
