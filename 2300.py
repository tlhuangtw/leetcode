class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        # sort potions
        potions.sort()
        # for spell_i, look for smallest potion_i where
        #   spell_i * potion_i >= success
        n, m = len(spells), len(potions)
        ans = []
        for i, s in enumerate(spells):
            if s * potions[-1] < success:
                ans.append(0)
                continue
            l, r = 0, m - 1
            while l < r:
                middle = (l + r) // 2
                if s * potions[middle] < success:
                    l = middle + 1
                else:
                    r = middle
            ans.append(m - l)
        return ans

