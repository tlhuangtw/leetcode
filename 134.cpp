class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas = std::accumulate(gas.begin(), gas.end(), 0);
        int sumCost = std::accumulate(cost.begin(), cost.end(), 0);

        if (sumGas < sumCost) {
            return -1;
        }

        int balance = 0, begin = 0;
        for (int i = 0; i < gas.size(); i++) {
            balance += gas[i] - cost[i];
            if (balance < 0) {
                balance = 0;
                begin = i + 1;
            }
        }

        return begin;
    }
};

