
# Weekly Contest Summary

|Date|Contest|Problem|Complexity|Solution|
|---|---|---|---|---|
|2019/11/17| WC163 | [二维网格迁移 Shift 2D Grid](https://leetcode-cn.com/problems/shift-2d-grid/) | E|[C++](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC_163_01_Shift_2D_Grid/WC_163_01_Shift_2D_Grid.cpp)|
|||[在受污染的二叉树中查找元素 Find Elements in a Contaminated Binary Tree](https://leetcode-cn.com/contest/weekly-contest-163/problems/find-elements-in-a-contaminated-binary-tree/)|M|略 ~~(其实是懒得看了)~~ |
|||[可被三整除的最大和 Greatest Sum Divisible By Three](https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/)|M|[C++](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC_163_03_Greatest_Sum_Divisible_by_Three/WC_163_03_Greatest_Sum_Divisible_by_Three.cpp) |
||||H|
|2019/11/10| WC162 | [奇数值单元格的数目 Cells with Odd Values in a Matrix](https://leetcode-cn.com/problems/cells-with-odd-values-in-a-matrix/) |E|[Python](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCPython/WC162_01_Cells_with_Odd_Values_in_a_Matrix.py)|
|||[重构 2 行二进制矩阵 Reconstruct a 2-Row Binary Matrix](https://leetcode-cn.com/problems/reconstruct-a-2-row-binary-matrix/)|M|[Python](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCPython/WC162_02_Reconstruct_a_2-Row_Binary_Matrix.py)|
|||[统计封闭岛屿的数目 Number of Closed Islands](https://leetcode-cn.com/problems/number-of-closed-islands/)|M|[C++](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC162_03_Number_of_Closed_Islands/WC162_03_Number_of_Closed_Islands.cpp)|
||||H||

#### WC163
这次竞赛气到昏过去，竟然一道题也没做出来。  

自我批评就省略了，分析一下原因。  

**第一题**想着一步到位，推数学式花了比较久，结果10分钟了还有case没过，就打算先做别的题。
其实这题模拟法三重循环直接能过。关于为什么直接模拟法就能过的计算方式，在[代码](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC_163_01_Shift_2D_Grid/WC_163_01_Shift_2D_Grid.cpp)里。

**第二题**题干太长直接没看，其实也不难。

**第三题**写了80分钟，换了两种思路，还是过不了。
竞赛完了，一看大佬@liaozhou_101的代码，代码特简洁，但是看都看不懂。 GG
仔细揣摩了一个小时。其实是这样的：
> 动态规划，dp[i][j]表示前i个数取若干个数后余j的最大和（其中，j只能为0，1，2）
> 更新时，依次更新余数为0，1，2的三种情况。对于每个余数只需考虑选取当前数与不选取当前数两种情况。
> 若上次余数为j，则此次若选取当前数，余数为 (j+nums[i-1])%3 ，记为x
> 若不选取当前数，余数应与选取当前数后余数一致，也为x  

因此，递推式 **dp[i][x] = max(dp[i-1][x], dp[i-1][j]+nums[i-1]**

#### WC162
第一题和第二题直接模拟法，一开始还担心会有case过不了，后来发现想多了。  

第三题想套用之前的模板做，花了70分钟也没做出来，赛后花了20分钟理思路，10分钟就写好了。
其实，只需要2次DFS即可。
第一次从边缘的所有点进行四邻域DFS，将途径的所有陆地设为2.
第二次遍历整个数组，每次发现一个陆地，都CNT++，并且对这个陆地进行DFS，所有途径的陆地设为3.
直接返回CNT即可。
在最终的数组中，1仍是水没有变动，2是与边缘相接的陆地，3是封闭的岛。

#### Rank
|No. | Rank| Overcome|
|---|---|---|
|WC163 |1500/1604 |6.5%|
|WC162 |451/1568 |71.2%|
|WC160 |207/1691 |**87.8%**|
|WC159 |539/1633 |67.0%|