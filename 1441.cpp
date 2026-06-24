class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int targetIdx = 0;
        int targetSize = target.size();
        vector<string> ops;
        ops.reserve(targetSize * 2);

        for (int i = 1; i <= n; ++i) {
            if (targetIdx == targetSize) {
                break;
            }

            ops.push_back("Push");
            if (i == target[targetIdx]) {
                targetIdx++;
            } else {
                ops.push_back("Pop");
            }
        }

        return ops;
    }
};

