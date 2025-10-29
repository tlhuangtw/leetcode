# ref: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/solutions/6276375/beats-100-find-the-prefix-common-array-b-4i3s

class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        ans = []
        freq = [0 for _ in range(n + 1)]
        common = 0

        for i in range(n):
            freq_ai = freq[A[i]]
            if freq_ai == 0:
                freq[A[i]] = 1
            else:
                common += 1
            freq_bi = freq[B[i]]
            if freq_bi == 0:
                freq[B[i]] = 1
            else:
                common += 1
            ans.append(common)

        return ans

