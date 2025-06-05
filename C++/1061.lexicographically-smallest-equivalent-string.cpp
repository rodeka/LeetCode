/*
 * @lc app=leetcode id=1061 lang=cpp
 *
 * [1061] Lexicographically Smallest Equivalent String
 */

// @lc code=start
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i = 0; i < s1.length(); i++) {
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';
            uni(a, b);
        }

        string ans;
        ans.reserve(baseStr.length());

        for(int i = 0; i < baseStr.length(); i++){
            int idx = baseStr[i] - 'a';
            int root = find(idx);
            char best = char(root + 'a');
            ans.push_back(best);
        }
        return ans;
    }

    vector<int> minParent = {
         0,  1,  2,  3,  4,  5,  6,  7,  8, 9,
        10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25
    };

    int find(int x) {
        if(minParent[x] != x){
            minParent[x] = find(minParent[x]);
        }
        return minParent[x];
    }

    void uni(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if(rx == ry) return;
        if(rx < ry) {
            minParent[ry] = rx;
        }
        else {
            minParent[rx] = ry;
        }
    }
};
// @lc code=end

