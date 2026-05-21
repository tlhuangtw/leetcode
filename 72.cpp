class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        if (m < n) {
            return minDistance(word2, word1);
        }

        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            dp[i] = i;
        }

        for (int i = 1; i <= m; ++i) {
            int d_i_1_j_1 = dp[0];
            dp[0] = i;

            for (int j = 1; j <= n; ++j) {
                int d_i_1_j = dp[j];

                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = d_i_1_j_1;
                } else {
                    dp[j] = min({d_i_1_j_1, dp[j - 1], dp[j]}) + 1;
                }

                d_i_1_j_1 = d_i_1_j;
            }
        }

        return dp.back();
    }
};

