class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> numSet(nums.begin(), nums.end());
        int ans = 0;

        for (const auto& num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLen = 1;

                while(numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLen++;
                }
                ans = max(ans, currentLen);
            }
        }

        return ans;
    }
};

