class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        int x = 1;
        for (int i = 1; i < n; ++i) {
            x *= nums[i - 1];
            ans[i] *= x;
        }

        int y = 1;
        for (int i = n - 2; i >= 0; --i) {
            y *= nums[i + 1];
            ans[i] *= y;
        }

        return ans; 
    }
};

