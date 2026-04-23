class Solution {
public:
    int rob(vector<int>& nums) {
        std::vector<int> dp = {nums[0]};
        dp.reserve(nums.size());

        if (nums.size() > 1) {
            dp.push_back(max(dp[0], nums[1]));
        }
        for (int i = 2; i < nums.size(); i++) {
            dp.push_back(max(dp[i - 1], dp[i - 2] + nums[i]));
        }

        return dp.back();
    }
};

