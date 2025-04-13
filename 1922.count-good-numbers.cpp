/*
 * @lc app=leetcode id=1922 lang=cpp
 *
 * [1922] Count Good Numbers
 */

// @lc code=start
class Solution {
private: 
    const int mod = 1000000007;
public:
    int countGoodNumbers(long long n) {
        return (long long)qPow(4, n/2) * qPow(5, (n+1)/2) % mod;
    }
    
    int qPow(int base, long long exp){
        int res = 1, mul = base;
        while(exp){
            if(exp % 2 == 1){
                res = (long long)res * mul % mod;
            }
            mul = (long long)mul * mul % mod;
            exp /= 2;
        }
        return res;
    }
};
// @lc code=end

