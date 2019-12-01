
# Weekly Contest Summary

|Date|Contest|Problem|Complexity|Solution|
|---|---|---|---|---|
|2019/12/01| WC165 |[找出井字棋的获胜者 Find Winner on a Tic Tac Toe Game](https://leetcode-cn.com/problems/find-winner-on-a-tic-tac-toe-game/) | E | 模拟法，没啥价值，不贴了 |
|||[不浪费原料的汉堡制作方案 Number of Bugers with no Waste of Ingredients](https://leetcode-cn.com/problems/number-of-burgers-with-no-waste-of-ingredients/) | M | 鸡兔同笼问题，没啥价值，不贴了 |
|||[统计全为1的正方形子矩阵 Count Square Submatrices with All Ones](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/)| M | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC165_03_Count_Square_Submatrices_With_All_Ones/WC165_03_Count_Square_Submatrices_With_All_Ones.cpp)
|||[分割回文串 III Palindrome Partitioning III](https://leetcode-cn.com/problems/palindrome-partitioning-iii/) | H | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC165_04%20_Palindrome_Partitioning_III/WC165_04%20_Palindrome_Partitioning_III.cpp)
|2019/11/24| WC164 |[访问所有点的最小时间 Minimum Time Visiting All Points](https://leetcode-cn.com/problems/minimum-time-visiting-all-points/) |E|[Python](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCPython/WC164_01_Minimum_Time_Visiting_All_Points.py)|
|||[统计参与通信的服务器 Count Servers That Communicate](https://leetcode-cn.com/problems/count-servers-that-communicate/)|M|[C++](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC164_02_Count_Servers_That_Communicate/WC164_02_Count_Servers_That_Communicate.cpp)|
|||[搜索推荐系统 Search Suggestions System](https://leetcode-cn.com/problems/search-suggestions-system/)|M|[Python](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCPython/WC164_03_Search_Suggestions_System.py)|
|||[停在原地的方案数 Number of Ways to Stay in the Same Place after Some Steps](https://leetcode-cn.com/contest/number-of-ways-to-stay-in-the-same-place-after-some-steps/)|H|[C++](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC164_04_Number_Of_Ways_To_Stay_In_The_Same_Place_After_Some_Steps/WC164_04_Number_Of_Ways_To_Stay_In_The_Same_Place_After_Some_Steps.cpp)|
|2019/11/17| WC163 | [二维网格迁移 Shift 2D Grid](https://leetcode-cn.com/problems/shift-2d-grid/) | E|[C++](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC_163_01_Shift_2D_Grid/WC_163_01_Shift_2D_Grid.cpp)|
|||[在受污染的二叉树中查找元素 Find Elements in a Contaminated Binary Tree](https://leetcode-cn.com/contest/weekly-contest-163/problems/find-elements-in-a-contaminated-binary-tree/)|M|略 ~~(其实是懒得看了)~~ |
|||[可被三整除的最大和 Greatest Sum Divisible By Three](https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/)|M|[C++](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC_163_03_Greatest_Sum_Divisible_by_Three/WC_163_03_Greatest_Sum_Divisible_by_Three.cpp) |
||||H|
|2019/11/10| WC162 | [奇数值单元格的数目 Cells with Odd Values in a Matrix](https://leetcode-cn.com/problems/cells-with-odd-values-in-a-matrix/) |E|[Python](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCPython/WC162_01_Cells_with_Odd_Values_in_a_Matrix.py)|
|||[重构 2 行二进制矩阵 Reconstruct a 2-Row Binary Matrix](https://leetcode-cn.com/problems/reconstruct-a-2-row-binary-matrix/)|M|[Python](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCPython/WC162_02_Reconstruct_a_2-Row_Binary_Matrix.py)|
|||[统计封闭岛屿的数目 Number of Closed Islands](https://leetcode-cn.com/problems/number-of-closed-islands/)|M|[C++](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC162_03_Number_of_Closed_Islands/WC162_03_Number_of_Closed_Islands.cpp)|
||||H||

#### WC165
希望以后都能保三冲四！
**第一题** 井字格游戏。基础编程能力还是有待提高，写这一题竟然花了30分钟。
**第二题** 鸡兔同笼思想，题目不难，但是Python语法越来越不熟悉了。
**第三题** 模拟二维矩阵求最大1为边正方形即可，加上动态规划，O(n^2)
1. dp数组的递推公式仅与其左，上，左上三个元素的值有关：dp[r][c] = min(dp[r-1][c], dp[r][c-1], dp[r-1][c-1])+1 if matrix[r][c]==1 else 0
2. 其含义是以当前元素作为右下角的正方形一共有多少个，或理解为，若想让某元素位置的dp值为n，则其左，左上，上三个元素的dp值必然为n-1（即，3*3正方形右下角顶点的左，左上，上三个位置的dp值必然为2）。 

**第四题** 自己没思路，看了讨论区才明白该怎么做。并且花了1个小时debug。。。bug是求字符串变为回文子串代价的那个函数中，求l的地方漏了括号，坑！！
1. cost[i][j] 表示将s[i..j] 变为回文串的代价
2. dp[i][j] 表示将前i个字符串划分为j个回文串的代价
3. dp[i][j] = min( dp[k][j-1]+cost[k][i-1] ) for k in [0,i) 
   即 前i个字符划分j个回文串的最小代价 = 前k个字符划分j-1个字符串 + 第k+1个字符至第i个字符变成回文串的代价

#### WC164
第一次完赛，撒花！！  

**第一题** 直接取 max(x_i - x_i-1, y_i - y_i-1) 作为两点之间的运动时间即可  
**第二题** 哪些服务器是无法参与通讯的？只有其所在行和列均只有一个服务器的那些不能参与通讯。再由 总服务器-孤独的服务器=可参与通讯的服务器  
**第三题** 我的算法T: O(nm), S: O(m) （其中n和m分别为len(products)和len(searchWord)），看了下题解，发现我这算法复杂度还算低的，而且也不需要额外的数据结构  
基本思路是，从头开始遍历searchWord的每个字母，将products中同样位置字符相同的product取出来构成new_products，其前三个加入返回的list中，再将整个new_products赋值给products供匹配下一个字母时使用。  
**第四题** 动态规划就完事了，控制复杂度的核心值`steps<500`，O(steps^2)<2.5*1e6，因此无需优化  

这次的题目整体上比较简单，基本不需要特殊的数据结构和算法就能直接过。
尽管如此，完赛还是很开心！
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

**总结**
经验教训就是一定不要贪多，循序渐进稳扎稳打，123题一道一道做。

#### WC162
第一题和第二题直接模拟法，一开始还担心会有case过不了，后来发现想多了。  

第三题想套用之前的模板做，花了70分钟也没做出来，赛后花了20分钟理思路，10分钟就写好了。
其实，只需要2次DFS即可。
第一次从边缘的所有点进行四邻域DFS，将途径的所有陆地设为2.
第二次遍历整个数组，每次发现一个陆地，都CNT++，并且对这个陆地进行DFS，所有途径的陆地设为3.
直接返回CNT即可。
在最终的数组中，1仍是水没有变动，2是与边缘相接的陆地，3是封闭的岛。

#### Rank
|No. | Rank| Percent|
|---|---|---|
|WC165 |312/1659  |18.8%|
|WC164 |145/1674  |**8.7%**|
|WC163 |1500/1604 |93.5%|
|WC162 |451/1568 |28.8%|
|WC160 |207/1691 |12.2%|
|WC159 |539/1633 |33.0%|