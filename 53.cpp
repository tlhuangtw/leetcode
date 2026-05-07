class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEndingHere = nums[0], maxSoFar = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }
};

