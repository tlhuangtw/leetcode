class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts;
        vector<int> ends;

        int n = intervals.size();
        starts.reserve(n);
        ends.reserve(n);

        for (const auto& interval : intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0;
        int endIdx = 0;
        for (int i = 0; i < n; ++i) {
            if (starts[i] < ends[endIdx]) {
                rooms++;
            } else {
                endIdx++;
            }
        }

        return rooms;
    }
};

