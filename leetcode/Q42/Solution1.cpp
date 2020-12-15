class Solution {
public:
    //method 2:
    //author Huahua:
    //https://www.youtube.com/watch?v=StH5vntauyQ
    int trap(vector<int>& height) {
        const int n=height.size();
        int ans=0;
        vector<int>l(n);
        vector<int>r(n);
        
        for(int i=0;i<n;i++)
            l[i]=(i==0?height[0]:max(l[i-1],height[i]));
        
        for(int i=n-1;i>=0;i--)
            r[i]=(i==n-1?height[n-1]:max(r[i+1],height[i]));
        
        for(int i=0;i<n;i++){
            ans=ans+(min(l[i],r[i])-height[i]);
        }
        return ans;
      
    }
};
