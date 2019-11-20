
```cpp{.line-numbers}
bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    // dp[i][j] denotes s[i:] match p[j:]

    dp.back().back() = true;
    for (int i = s.size(); i != -1; --i) {
        for (int j = p.size() - 1; j != -1; --j) {
            bool first_match = i<s.size() && (s[i] == p[j] || p[j] == '.'); 
            if (j+1<p.size() && p[j + 1] == '*')
                dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
            else
                dp[i][j] = first_match && dp[i + 1][j + 1];
            printMatrix(dp);
        }
    }
    return dp[0][0];
}
```

这题的代码确实不好理解，需要配合图片记忆
以"baa"和".a*"匹配为例，其逐步dp更新的过程在最后的图片里，这里展示一下中间过程
@import "process_zoomin.png" {width=200}
除了dp[-1][-1]是初始化时更新为true，其他皆为false。
想让false变为true有三种情况，分别是上1，左2，左上三种箭头
左一对应代码第十行前一种情况，表示类似   "" match "a*"      <---    "" match ""，    这种情况下dp[i][j]与dp[i][j+2]有关
上一对应代码第十行第二种情况，表示类似   "a" match "a*"     <---    "" match "a*"， 这种情况下dp[i][j]与dp[i+1][j]有关
左上对应代码第十二行，表示类似          "a" match ".a*"     <---    "" match "a*"， 这种情况下dp[i][j]与dp[i+1][j+1]有关

@import "process.png"