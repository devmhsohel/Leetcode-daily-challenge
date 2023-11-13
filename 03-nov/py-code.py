class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        stack = []
        result = []
        for i in range(1, n + 1):
            if not target:
                break
            if i == target[0]:
                stack.append(i)
                result.append("Push")
                target.pop(0)
            else:
                stack.append(i)
                result.append("Push")
                stack.pop()
                result.append("Pop")
        return result