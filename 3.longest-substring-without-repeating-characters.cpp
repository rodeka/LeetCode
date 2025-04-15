/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned short where_last_see[95];
        for(char i = 0; i < 95; i++){
            where_last_see[i] = 65535;
        }

        unsigned short res = 0, j = 0;
        for(unsigned short i = 0; i < s.size(); i++){
            if(where_last_see[s[i] - ' '] >= j && where_last_see[s[i] - ' '] != 65535){
                j = where_last_see[s[i] - ' '] + 1;
            }
            where_last_see[s[i] - ' '] = i;
            res=max(res, (unsigned short)(i - j + 1));
        }
        return res;
    }


};
// @lc code=end

