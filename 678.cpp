class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0;
        int cmax = 0;

        for (const auto& c : s) {
            if (c == '(') {
                cmin++;
                cmax++;
            } else if (c == ')') {
                cmin = max(0, cmin - 1);
                cmax--;
            } else {
                cmin = max(0, cmin - 1);
                cmax++;
            }

            if (cmax < 0) {
                return false;
            }
        }

        return cmin == 0;
    }
};

