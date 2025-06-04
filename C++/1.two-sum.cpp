/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<pair<int, int>> new_nums(nums.size());
            for(int i=0; i<nums.size(); i++){
                new_nums[i] = make_pair(nums[i], i);
            }
            struct{
                bool operator()(pair<int, int> a, pair<int, int> b) {return a.first < b.first; }
            }
            customLess;
            sort(new_nums.begin(), new_nums.end(), customLess);
    
            int i=0, j=new_nums.size()-1;
            while(new_nums[i].first+new_nums[j].first!=target){
                if(new_nums[i].first+new_nums[j].first>target)
                    j--;
                else
                    i++;
            }
            return {new_nums[i].second, new_nums[j].second};
        }
    };
// @lc code=end

