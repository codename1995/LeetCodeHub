class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        // dp[i][j]==true denotes that s[i:] match p[j:]
        
        dp.back().back() = true;
        for (int i=s.size();i!=-1;i--){
            for (int j=p.size()-1;j!=-1;j--){
                bool first_match = i<s.size() and (p[j]==s[i] or p[j]=='.');
                if (j+1<p.size() and p[j+1]=='*')
                    dp[i][j] = dp[i][j+2] or first_match and dp[i+1][j];
                else
                    dp[i][j] = first_match and dp[i+1][j+1];
            }
        }    
        return dp[0][0];
    }
};