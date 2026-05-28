class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        seen.reserve(nums.size());
        for (const auto& num : nums) {
            if (!(seen.insert(num).second)) {
                return true;
            }
        }

        return false;
    }
};

