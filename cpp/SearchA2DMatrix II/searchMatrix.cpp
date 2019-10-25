class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=0;
        if (matrix.size()<=0) return false;
        int c=matrix[0].size()-1;
        while (r!=matrix.size() && c!=-1){
            if (matrix[r][c] < target)
                r++;
            else if (matrix[r][c] > target)
                c--;
            else
                return true;
           //cout << r << c << endl;
        }
        return false;
    }
};