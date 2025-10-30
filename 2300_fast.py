# ref: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/solutions/7257556/sort-then-binary-search29-ms-beats-9807-y2w9n

from collections import Counter
from itertools import accumulate

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        # counting sort
        potions_freq = Counter(potions)
        max_potion = max(potions_freq)
        raw_count_table = [0 for _ in range(max_potion + 1)]
        for potion, freq in potions_freq.items():
            raw_count_table[potion] = freq
        count_table = list(accumulate(raw_count_table))
        # construct the solution
        n, m = len(spells), len(potions)
        ans = [0 for _ in range(n)]
        for i, spell in enumerate(spells):
            k = (success + spell - 1) // spell  # calculate ceiling(success // spell)
            if k <= max_potion:  # we consider potions >= k
                ans[i] = m - count_table[k - 1]
        return ans

