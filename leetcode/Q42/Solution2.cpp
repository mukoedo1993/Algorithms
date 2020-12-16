
// Author: Huahua, 4 ms, 9.1 MB
class Solution {
public:
  int trap(vector<int>& height) {
    const int n = height.size();
    if (n == 0) return 0;
    int l = 0;
    int r = n - 1;
    int max_l = height[l];
    int max_r = height[r];
    int ans = 0;
    while (l < r) {      
      if (max_l < max_r) {
        ans += max_l - height[l];
        max_l = max(max_l, height[++l]);
      } else {
        ans += max_r - height[r];
        max_r = max(max_r, height[--r]);
      }
    }
    return ans;
  }
};
