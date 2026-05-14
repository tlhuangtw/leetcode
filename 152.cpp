class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMin = nums[0];
        int currentMax = nums[0];
        int globalMax = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            int num = nums[i];

            if (num < 0) {
                swap(currentMin, currentMax);
            }

            currentMin = min(num, currentMin * num);
            currentMax = max(num, currentMax * num);
            globalMax = max(globalMax, currentMax);
        }

        return globalMax;
    }
};

