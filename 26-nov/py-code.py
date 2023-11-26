class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        cm = zip(*(accumulate(c, lambda a,v: a*v+v) for c in zip(*matrix)))
        return max((i*v for r in cm for i,v in enumerate(takewhile(lambda x: bool(x), sorted(r, reverse=True)),start=1)), default=0)


class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        row, col = len(matrix), len(matrix[0])

        # Calculate heights for each column
        for i in range(1, row):
            for j in range(col):
                if matrix[i][j] == 1:
                    matrix[i][j] += matrix[i - 1][j]

        res = 0
        for i in range(row):
            # Sort the heights in ascending order
            matrix[i].sort()

            # Iterate through the sorted heights
            for j in range(col):
                height = matrix[i][j]
                width = col - j
                res = max(res, height * width)

        return res