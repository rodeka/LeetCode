/*
 * @lc app=leetcode id=2434 lang=cpp
 *
 * [2434] Using a Robot to Print the Lexicographically Smallest String
 */

// @lc code=start
class Solution {
public:
    string robotWithString(string s) {
        vector<int> pos(26, -1);
        for(int i = 0; i < s.length(); i++) {
            pos[s[i] - 'a'] = i;
        }

        string ans;
        ans.reserve(s.length());
        int j = 0;
        stack<char> t;
        for(int i = 0; i < 26 && j < s.length(); i++) {
            if(pos[i] == -1) continue;
            while(t.empty() == false && t.top() <= char(i + 'a')) {
                ans.push_back(t.top());
                t.pop();
            }
            while(j <= pos[i]) {
                t.push(s[j]);
                j++;
                if(t.top() == char(i + 'a')) {
                    ans.push_back(t.top());
                    t.pop();
                }
            }
        }
        while(!t.empty()){
            ans.push_back(t.top());
            t.pop();
        }
        return ans;
    }
};
// @lc code=end

