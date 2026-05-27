class Solution {
public:
    int hammingWeight(int n) {
        uint32_t unsigned_n = (uint32_t)n;
        int ans = 0;

        while (unsigned_n > 0) {
            if (unsigned_n & 1) {
                ans++;
            }
            unsigned_n >>= 1;
        }

        return ans;
    }
};

