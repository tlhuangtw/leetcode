class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool found_a = false;
        bool found_b = false;
        bool found_c = false;

        for (const auto& t : triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
                continue;
            }

            if (t[0] == target[0]) {
                found_a = true;
            }
            if (t[1] == target[1]) {
                found_b = true;
            }
            if (t[2] == target[2]) {
                found_c = true;
            }

            if (found_a && found_b && found_c) {
                break;
            }
        }

        return found_a && found_b && found_c;
    }
};

