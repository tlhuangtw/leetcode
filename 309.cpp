class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];
        int sold = 0;
        int rest = 0;

        for (const auto& price : prices) {
            int prev_hold = hold;
            int prev_sold = sold;
            int prev_rest = rest;

            hold = max(prev_hold, prev_rest - price);
            sold = prev_hold + price;
            rest = max(prev_sold, prev_rest);
        }

        return max(sold, rest);
    }
};

