class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp = {1, 1, 2};
        dp.reserve(46);

        for (int i = 3; i < 46; i++) {
            auto n = dp.size();
            dp.push_back(dp[n - 1] + dp[n - 2]);
        }

        return dp[n];
    }
};

