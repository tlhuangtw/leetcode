class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        array<int, 26> freq = {};
        int maxFreq = 0;

        for (const auto& task : tasks) {
            freq[task - 'A']++;
            maxFreq = max(maxFreq, freq[task - 'A']);
        }

        int maxFreqTasks = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == maxFreq) {
                maxFreqTasks++;
            }
        }

        int result = (maxFreq - 1) * (n + 1) + maxFreqTasks;
        int taskSize = tasks.size();
        return max(result, taskSize);
    }
};

