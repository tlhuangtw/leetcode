class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size()) {
            std::swap(text1, text2);
        }
        std::vector<std::vector<int>> dp(2, std::vector<int>(text2.size() + 1, 0));
        int cur = 1, pre = 0;

        for (int i = 0; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    dp[cur][j + 1] = dp[pre][j] + 1;
                } else {
                    dp[cur][j + 1] = max(dp[pre][j + 1], dp[cur][j]);
                }
            }
            cur = 1 - cur;
            pre = 1 - pre;
        }

        return dp[1 - cur].back();
    }
};

