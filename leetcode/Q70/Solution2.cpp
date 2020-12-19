//Original author: Huahua
//https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-70-climbing-stairs/
//Memory usage O(1)
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        int tmp1=1;
        int tmp2=2;
        int curr;
        for(int i=3;i<=n;i++)
        {curr=tmp1+tmp2;
          tmp1=tmp2;
           tmp2=curr;
         }
        return curr;
    }

   
};
