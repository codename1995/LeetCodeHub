class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[False for _ in range(len(p) + 1)] for _ in range(len(s) + 1)]
        # dp[i][j] denotes s[i:] match p[j:]

        dp[-1][-1] = True

        for i in range(len(s), -1, -1):
            for j in range(len(p) - 1, -1, -1):
                first_match = i < len(s) and p[j] in {s[i], '.'}
                if j + 1 < len(p) and p[j + 1] == '*':
                    dp[i][j] = dp[i][j + 2] or first_match and dp[i + 1][j]
                else:
                    dp[i][j] = first_match and dp[i + 1][j + 1]
        return dp[0][0] 