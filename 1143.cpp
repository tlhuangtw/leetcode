class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size()) {
            return longestCommonSubsequence(text2, text1);
        }
        int m = text1.size();
        int n = text2.size();
        std::vector<int> dp(n + 1, 0);

        for (int i = 1; i <= m; ++i) {
            int dp_i_1_j_1 = 0; // act as dp[i - 1][j - 1]

            for (int j = 1; j <= n; ++j) {
                int dp_i_1_j = dp[j]; // act as dp[i - 1][j]

                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = dp_i_1_j_1 + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                dp_i_1_j_1 = dp_i_1_j;
            }
        }

        return dp.back();
    }
};

