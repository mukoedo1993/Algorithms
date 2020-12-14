//Author mukoedo1993:
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      
        nums1.insert(nums1.end(),move_iterator(nums2.cbegin()),move_itertaor(nums2.cend()));sort(nums1.begin(),nums1.end());
        const int size=nums1.size();
        if(size%2)
            return nums1[size/2];
        else
            return static_cast<double>(nums1[size/2-1]+nums1[size/2])/2;
       
    }
};
