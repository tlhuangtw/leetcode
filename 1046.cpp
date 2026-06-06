class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int x = maxHeap.top(); maxHeap.pop();
            int y = maxHeap.top(); maxHeap.pop();

            if (x > y) {
                maxHeap.push(x - y);
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

