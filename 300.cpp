class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> tails(nums.size(), 0);
        int size = 0;

        for (const auto& n : nums) {
            int i = 0, j = size;
            while (i < j) {
                int m = (i + j) / 2;
                if (n > tails[m]) {
                    i = m + 1;
                } else {
                    j = m;
                }
            }
            tails[i] = n;
            size = max(size, i + 1);
        }

        return size;
    }
};

