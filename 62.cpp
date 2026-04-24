// ref: https://leetcode.com/problems/unique-paths/solutions/1581998/cpython-5-simple-solutions-w-explanation-zzhs

class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for (int i = m + n - 2, j = 1; i >= max(m, n); i--, j++) {
            ans = ans * i / j;
        }
        return ans;
    }
};

