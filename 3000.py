class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        max_squared_diagonal, area = 0, 0
        for l, w in dimensions:
            squared_diaginal = l * l + w * w
            if squared_diaginal > max_squared_diagonal:
                max_squared_diagonal = squared_diaginal
                area = l * w
            elif squared_diaginal == max_squared_diagonal:
                if l * w > area:
                    area = l * w
        return area

