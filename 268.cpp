class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int xor_nums = accumulate(nums.begin(), nums.end(), 0, [](int a, int b) {
            return a ^ b;
        });

        int xor_total = 0;
        for (int i = 0; i <= n; ++i) {
            xor_total ^= i;
        }

        return xor_total ^ xor_nums;
    }
};

