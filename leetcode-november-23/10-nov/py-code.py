class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        adjacent = defaultdict(list)
        for u, v in adjacentPairs:
            adjacent[u].append(v)
            adjacent[v].append(u)

        array = []
        for num, neighbours in adjacent.items():
            if len(neighbours) == 1:
                array = [num, neighbours[0]]
                break

        while len(array) < len(adjacentPairs) + 1:
            u, v = adjacent[array[-1]]
            array.append(u if array[-2] == v else v)
        return array