class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total_sum || (total_sum + target) % 2 == 1) {
            return 0;
        }

        int subset_target = (total_sum + target) / 2;
        vector<int> dp(subset_target + 1, 0);

        dp[0] = 1;
        for (const auto& num : nums) {
            for (int i = subset_target; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }

        return dp.back();
    }
};

