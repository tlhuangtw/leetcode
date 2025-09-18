# ref: https://leetcode.com/problems/repeated-string-match/solutions/6177056/efficient-and-simple-solution-python-java-c-javascript-kotlin-go
# ref: https://stackoverflow.com/questions/18139660/python-string-in-operator-implementation-algorithm-and-time-complexity

class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        repeated_num = ceil(len(b) / len(a))  # minimum repeat times
        repeated_a = a * repeated_num
        if b in repeated_a:
            return repeated_num
        else:
            repeated_a += a
            if b in repeated_a:
                return repeated_num + 1  # try to append one more a
        return -1

