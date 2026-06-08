class Solution {
private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        int n = nums.size();
        if (start == n) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < n; ++i) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};

