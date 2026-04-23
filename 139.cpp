class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<bool> dp(s.size(), false);

        std::string_view sv = s;
        for (int i = 0; i < s.size(); i++) {
            for (const auto& word: wordDict) {
                auto w_size = word.size();
                if (i + 1 == w_size && sv.substr(0, w_size) == word || i + 1 > w_size && sv.substr(i - w_size + 1, w_size) == word && dp[i - w_size]) {
                    dp[i] = true;
                }
            }
        }

        return dp.back();
    }
};

