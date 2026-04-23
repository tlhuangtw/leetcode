class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 0x3f3f3f3f;
        std::vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (const auto& coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp.back() == INF ? -1 : dp.back();
    }
};

