class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        # construct the graph
        graph = [set() for _ in range(n)]
        for e in edges:
            graph[e[0]].add(e[1])
            graph[e[1]].add(e[0])
        # DFS: f(p) = sum(f(child))
        #      1. f(child) > 0: f(child) + 2
        #      2. f(child) = 0 and child has an apple: 2
        visited = [False for _ in range(n)]

        def dfs(node):
            val = 0
            visited[node] = True
            for child in graph[node]:
                if not visited[child]:
                    child_val = dfs(child)
                    if child_val > 0:
                        val += child_val + 2
                    elif child_val == 0 and hasApple[child]:
                        val += 2
            return val

        return dfs(0)

