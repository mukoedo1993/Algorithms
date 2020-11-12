Remember to use the dp.
dp[n][m]==is_valid(s.substr(0,n),p.substr(0,m)).
But keep in mind that substr is unforgivably slow in the leetcode.

Runtime: 36 ms, faster than 75.11% of C++ online submissions for Wildcard Matching.
Memory Usage: 8.1 MB, less than 5.02% of C++ online submissions for Wildcard Matching.
