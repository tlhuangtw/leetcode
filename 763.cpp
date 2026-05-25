class Solution {
public:
    vector<int> partitionLabels(string s) {
        array<int, 26> last_occurrence{};
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            last_occurrence[s[i] - 'a'] = i;
        }

        vector<int> partitions;
        int start = 0;
        int end = 0;

        for (int i = 0; i < n; ++i) {
            end = max(end, last_occurrence[s[i] - 'a']);
            if (i == end) {
                partitions.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return partitions;
    }
};

