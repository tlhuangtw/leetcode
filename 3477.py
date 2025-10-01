class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        ans = len(fruits)
        for i, num_fruit in enumerate(fruits):
            for j, basket_size in enumerate(baskets):
                if basket_size >= num_fruit:
                    baskets[j] = 0
                    ans -= 1
                    break
        return ans

