class Solution:
    def minTimeToVisitAllPoints(self, points):
        if (len(points) == 1): return 0
        x0, y0 = points[0]
        cnt = 0
        for [x, y] in points:
            cnt += max(abs(x - x0), abs(y - y0))
            x0, y0 = x, y

        return cnt