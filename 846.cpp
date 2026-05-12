class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        std::map<int, int> count;
        for (const auto& card : hand) {
            count[card]++;
        }

        for (auto it = count.begin(); it != count.end(); it++ ) {
            int first = it->first, freq = it->second;

            if (freq > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (count[first + i] < freq) {
                        return false;
                    }
                    count[first + i] -= freq;
                }
            }
        }

        return true;
    }
};

