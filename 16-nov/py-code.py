class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        result = ''.join('1' if num[idx] == '0' else '0' for idx, num in enumerate(nums))
        return result