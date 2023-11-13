class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        n = len(dist)
        time = [dist[i] / speed[i] for i in range(n)]
        time.sort()
        for i in range(n):
            if time[i] <= i:
                return i
        return n