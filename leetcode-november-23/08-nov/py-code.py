class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        xd = abs(sx - fx)
        yd = abs(sy - fy)

        if xd == 0 and yd == 0 and t == 1:
            return False

        return t >= max(xd, yd)

class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        return False if t == 1 and sx == fx and sy == fy else max((abs(sx - fx)), (abs(sy - fy))) <= t