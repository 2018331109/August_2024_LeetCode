/*
264. Ugly Number II
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

 

Constraints:

    1 <= n <= 1690

*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n, 0);
        dp[0]=1;
        int p1=0, p2=0, p3=0;
        for(int i=1;i<n;i++){
            int twom=dp[p1]*2;
            int threem=dp[p2]*3;
            int fivem=dp[p3]*5;
            dp[i]=min(twom, min(threem, fivem));

            if(dp[i]==twom) p1++;
            if(dp[i]==threem) p2++;
            if(dp[i]==fivem) p3++;
        }
        return dp[n-1];
    }
};
