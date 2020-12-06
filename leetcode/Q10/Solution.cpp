//author Huahua
//modefied by: mukoedo1993
class Solution {
public:
  bool isMatch(const string &s, const string &p){
     return isMatch(s.c_str(),p.c_str());
  }
    private:
      bool isMatch(const char*s,const char*p)
      {
          //case 1: p[0]=='\0'
          if(p[0]=='\0')return s[0]=='\0';
          
          
          //case 2: p[1]!='*'
          if(p[1]!='*')
          {
              if(s[0]=='\0')return false;//if s is already null, but p[1] is not a '*', then  it's
              //false.
              
              //otherwise, s's length is not smaller than 1.
              if(p[0]==s[0]||p[0]=='.')
                  return isMatch(s+1,p+1);
              else return false;
          }
          //case 3: p[1]=='*'
          else
          {
              if(isMatch(s,p+2))return true;
              if(s[0]=='\0')return false;
              int i=1;
              while(s[i-1]==p[0]||p[0]=='.')
              {
                  if(isMatch(s+i,p+2))return true;
                  //p[i] is apparently not '\0'.
                  //otherwise, if s[i]=='\0' then it could only be false.
                  if(s[i++]=='\0')return false;
              }
          }
          return false;
      }
};
