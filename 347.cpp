class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (const auto& num : nums) {
            freq[num]++;
        }

        vector<vector<int>> bucket(n + 1);
        for (const auto& [num, freq] : freq) {
            bucket[freq].push_back(num);
        }

        vector<int> result;
        result.reserve(k);
        for (int i = n; i >= 0 && result.size() < k; --i) {
            for (const auto& num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    break;
                }
            }
        }

        return result;
    }
};

