//Author: Leetcode official
//Although it passed all the tests, I believe that Huahua's solution is flawed.
//Leetcode gives a better solution. 
class Solution {
public:
  int reverse(int x) {
    int rev=0;
      while(x){
         int pop=x%10;
          x/=10;
          if(rev>INT_MAX/10||
            (rev==INT_MAX/10&&pop>7))return 0;
          if(rev<INT_MIN/10||
             (rev==INT_MIN/10&&pop<-8))return 0;
          rev=rev*10+pop;
      }
      return rev;
  }
};
