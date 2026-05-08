class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, curMaxReach = 0, currentJumpEnd = 0, n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            curMaxReach = max(curMaxReach, i + nums[i]);
            if (i == currentJumpEnd) {
                ans++;
                currentJumpEnd = curMaxReach;
            }
        }

        return ans;
    }
};

