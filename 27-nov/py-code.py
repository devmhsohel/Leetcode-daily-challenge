ANS = [10, 20, 46, 104, 240]
MOD = 1000_000_007

class Solution:
    def knightDialer(self, n: int) -> int:
        if n <= len(ANS): return ANS[n-1]
        a,b,c,d = ANS[-4:]
        for _ in repeat(0, n-len(ANS)):
            a,b,c,d = b,c,d, (c*6-a*4) % MOD
        return d

    def knightDialer(self, n: int) -> int:
        if n <= len(ANS): return ANS[n-1]
        for _ in repeat(0, n-len(ANS)):
            ANS.append((ANS[-2]*6-ANS[-4]*4)%MOD)
        return ANS[-1]


class Solution:
    def knightDialer(self, n: int) -> int:
        return sum(reduce(lambda dp, _: [sum(dp[i] for i in d) for d in [(4, 6), (6, 8), (7, 9), (4, 8), (3, 9, 0), (), (1, 7, 0), (2, 6), (1, 3), (2, 4)]], range(n-1), [1] * 10)) % (10**9+7)










class Solution:
    def knightDialer(self, n: int) -> int:
        dp = [1] * 10
        direct = [(4, 6), (6, 8), (7, 9), (4, 8), (3, 9, 0), (), (1, 7, 0), (2, 6), (1, 3), (2, 4)]
        for _ in range(n-1):
            dp = [sum(dp[i] for i in d) for d in direct]
        return sum(dp)%(10**9+7)