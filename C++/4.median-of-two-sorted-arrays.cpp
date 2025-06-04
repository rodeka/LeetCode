/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
    
        int n = nums1.size();
        int m = nums2.size();
        int low = 0, high = n;
    
        while(low <= high){
            int partitionN = (low + high) / 2;
            int partitionM = (n + m + 1) / 2 - partitionN;
    
            int maxLeftN = (partitionN == 0) ? INT_MIN : nums1[partitionN - 1];
            int minRightN = (partitionN == n) ? INT_MAX : nums1[partitionN];
    
            int maxLeftM = (partitionM == 0) ? INT_MIN : nums2[partitionM - 1];
            int minRightM = (partitionM == m) ? INT_MAX : nums2[partitionM];
    
            if(maxLeftN <= minRightM && maxLeftM <= minRightN){
                if((n + m) % 2 == 0){
                    return (max(maxLeftN, maxLeftM) + min(minRightN, minRightM)) / 2.0;
                } 
                else{
                    return max(maxLeftN, maxLeftM);
                }
            } 
            else if(maxLeftN > minRightM){
                high = partitionN - 1;
            } 
            else{
                low = partitionN + 1;
            }
        }

        return 0.0;
    }
};
// @lc code=end

