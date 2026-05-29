class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        array<int, 26> s1Count = {};
        array<int, 26> s2Count = {};
        int s1Size = s1.size();
        for (int i = 0; i < s1Size; ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }
        if (s1Count == s2Count) {
            return true;
        }

        int s2Size = s2.size();
        for (int i = 0; i < s2Size - s1Size; ++i) {
            s2Count[s2[i] - 'a']--;
            s2Count[s2[i + s1Size] - 'a']++;
            if (s1Count == s2Count) {
                return true;
            }
        }

        return false;
    }
};

