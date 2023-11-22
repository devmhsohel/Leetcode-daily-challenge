class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        return[all(c[i+1]-c[i]==c[1]-c[0]for i in range(len(c)-1))for c in[sorted(nums[x:y+1])for x,y in zip(l,r)]]