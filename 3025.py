# ref: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/solutions/7146299/same-as-the-hard-lc-3027-beats-100

class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        # sort x decreasingly and y increasingly
        points.sort(key=lambda v: (-v[0], v[1]))
        n = len(points)
        ans = 0
        for i in range(n - 1):
            last_upper_left_y = 1 << 31
            for j in range(i + 1, n):
                if last_upper_left_y > points[j][1] >= points[i][1]:
                    ans += 1
                    last_upper_left_y = points[j][1]
        return ans

