//Huahua
//https://zxi.mytechroad.com/blog/stack/leetcode-32-longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
       
       stack<int>q;
        int start=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                q.push(i);
            }else{
                if(q.empty()){
                    start=i+1;//update the starting point
                }else{
                    q.pop();
                    ans=max(ans,q.empty()?i-start+1:i-q.top());
                    //if q is empty, then i-start+1 is the current largest size
                    //If not, then i-q.top() is the current largest size
                }
                    
            }
                
        }
        return ans;
    }
};
