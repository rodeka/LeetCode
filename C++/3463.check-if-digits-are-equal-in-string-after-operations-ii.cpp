/*
 * @lc app=leetcode id=3463 lang=cpp
 *
 * [3463] Check If Digits Are Equal in String After Operations II
 */

// @lc code=start
class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length() - 2;

        int sum2 = 0;
        for(int i = 0; i <= n; i++) {
            if((i & (n - i)) == 0) {
                int di = (s[i] - '0') & 1;
                int dj = (s[i + 1] - '0') & 1;
                int xi2 = (di - dj) % 2;
                sum2 ^= xi2;
            }
        }

        int sum5 = 0;
        for(int i = 0; i <= n; i++) {
            int di = s[i] - '0';
            int dj = s[i + 1] - '0';
            int diff5 = (di - dj) % 5;
            if (diff5 < 0) diff5 += 5;
            int c5 = C_mod5(n, i);
            sum5 = (sum5 + c5 * diff5) % 5;
        }

        int mod10 = -1;
        for(int k = sum2; k < 10; k += 2){
            if(k % 5 == sum5) {
                mod10 = k;
                break;
            }
        }
        return (mod10 == 0);
    }

    static constexpr int C5[5][5] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 2, 1, 0, 0},
        {1, 3, 3, 1, 0},
        {1, 4, 1, 4, 1}
    };

    inline int C_mod5(int n, int k) {
        int result = 1;
        while (n > 0 || k > 0) {
            int ni = n % 5;
            int ki = k % 5;
            if (ki > ni) return 0;
            result = (result * C5[ni][ki]) % 5;
            n /= 5;
            k /= 5;
        }
        return result;
    }

};
// @lc code=end

