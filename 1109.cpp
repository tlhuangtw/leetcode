class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> delta(n + 1);

        for (const auto& booking : bookings) {
            int first = booking[0];
            int last = booking[1];
            int seats = booking[2];

            delta[first - 1] += seats;
            delta[last] -= seats;
        }

        vector<int> answer(n);
        int curSeat = 0;
        for (int i = 0; i < n; i++) {
            curSeat += delta[i];
            answer[i] = curSeat;
        }

        return answer;
    }
};

