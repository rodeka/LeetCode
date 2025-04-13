/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> searchNum;
        for(int i=0; i<nums.size(); i++){
            if(searchNum.find(target-nums[i])!=searchNum.end()){
                return 
            }
        }
    }
};
// @lc code=end

