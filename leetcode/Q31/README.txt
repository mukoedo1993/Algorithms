Actually, the stl next_permutation is nearly perfect.
See the implementation:

template<class BidirIt>
bool next_permutation(BidirIt first, BidirIt last)
{
    if (first == last) return false;
    BidirIt i = last;
    if (first == --i) return false;
 
    while (true) {
        BidirIt i1, i2;
 
        i1 = i;
        if (*--i < *i1) {
            i2 = last;
            while (!(*i < *--i2))
                ;
            std::iter_swap(i, i2);
            std::reverse(i1, last);
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}

See Huahua's soln:
//https://zxi.mytechroad.com/blog/algorithms/array/leetcode-31-next-permutation/
// Author: Huahua, 8 ms
class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) --i;
    if (i >= 0) {
      int j = nums.size() - 1;
      while (j >= 0 && nums[j] <= nums[i]) --j;
      swap(nums[i], nums[j]);
    }
    reverse(begin(nums) + i + 1, end(nums));
  }
};

See my solution:
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};
