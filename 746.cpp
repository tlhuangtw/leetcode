class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> dp = {cost[0], cost[1]};
        dp.reserve(cost.size());


        for (int i = 2; i < cost.size(); i++) {
            dp.push_back(min(dp[i - 1], dp[i - 2]) + cost[i]);
        }
        return min(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};

