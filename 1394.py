class Solution:
    def findLucky(self, arr: List[int]) -> int:
        count = {}
        for n in arr:
            if n in count:
                count[n] += 1
            else:
                count[n] = 1
        ans = -1
        for n in count:
            if count[n] == n and n > ans:
                ans = n
        return ans

