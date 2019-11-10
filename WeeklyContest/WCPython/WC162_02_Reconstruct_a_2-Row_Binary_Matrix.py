class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        res = [[0 for _ in range(len(colsum))] for _ in range(2)]
        for i,val in enumerate(colsum):
            if val==2:
                res[0][i] = 1
                res[1][i] = 1
                upper -= 1
                lower -= 1
                colsum[i] = 0
            elif val==1:
                if upper>lower:
                    res[0][i] = 1
                    upper -=1
                else:
                    res[1][i] = 1
                    lower -=1
                colsum[i] = 0
            if upper<0 or lower <0: return []
        if upper!=0 or lower!=0: return []
        return res