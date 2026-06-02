class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);

        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], ((double)target - position[i]) / speed[i]};
        }

        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        int ans = 0;
        double slowestTime = 0;
        for (const auto& car : cars) {
            if (car.second > slowestTime) {
                slowestTime = car.second;
                ans++;
            }
        }

        return ans;
    }
};

