class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int m = num1.size();
        int n = num2.size();
        vector<int> ans(m + n, 0);

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int val = (num1[i] - '0') * (num2[j] - '0');
                int idx2 = i + j + 1;
                int idx1 = i + j;

                int sum = val + ans[idx2];
                ans[idx2] = sum % 10;
                ans[idx1] += sum / 10; 
            }
        }

        string res;
        res.reserve(m + n);
        for (const auto& digit : ans) {
            if (!(res.empty() && digit == 0)) {
                res.push_back('0' + digit);
            }
        }

        return res;
    }
};

