
# Weekly Contest Summary

|Date|Contest|Problem|Complexity|Solution|
|---|---|---|---|---|
|2021/05/15|BiWC52_01|Sorting the Sentence|E|熟练运用split, sort, join之后，三行代码搞定 </br> words = s.split() </br> words.sort(key=lambda x:x[-1]) </br> return ' '.join(w[:-1] for w in words)|
||BiWC52_02|Incremental Memory Leak|M|略|
||BiWC52_03|Rotating the Box|M|先假装改变重力方向为朝右，得到矩阵B，再根据旋转后的坐标变换关系查询矩阵B|
||BiWC52_04|Sum of Floored Pairs|H|创建一个计数矩阵C和一个累加矩阵A，外循环v遍历1至maxx，内循环k遍历1至vk<=maxx。关键等式：v_based_sum = C[v]*(A[maxx]-A[vk-1])|
|2021/02/07|WC227_01|[Check if Array Is Sorted and Rotated](https://leetcode-cn.com/problems/check-if-array-is-sorted-and-rotated/) | E | 数量级小的时候考虑Brute-force，如本题|
||WC227_02|[Maximum Score From Removing Stones](https://leetcode-cn.com/problems/maximum-score-from-removing-stones/)|M|经典问题，可扩展到多堆。</br> 1. 若最大堆的石子数量大于其他堆之和，则答案为其他堆石子数量之和 </br> 2. 否则，答案为 石子总数除以二并向下取整 的值
||WC227_03|[Largest Merge Of Two Strings](https://leetcode-cn.com/problems/largest-merge-of-two-strings/)|M| 直接用word1和word2的余下全字段比较，使用更“大”者的首字母，并将头指针往后移一位即可；最后记得将未用完的字段补在res后即可。|
|2021/01/31|WC226_01|[Maximum Number of Balls in a Box](https://leetcode-cn.com/problems/maximum-number-of-balls-in-a-box/)|E|略|
||WC226_02|[Restore The Array From Adjacent Pairs](https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs/) | M| 哈希表(k=value, v=[cnt, v1, v2])先遍历adjacentPairs 建立哈希表，然后遍历哈希表找到头或尾，最好自找到的值开始还原表 [Python](https://github.com/codename1995/leetcodehub/blob/master/python/WC226_02_Restore_The_Array_From_Adjacent_Pairs.py)|
||WC226_03| [Can YouEat Your Favorite Candy on Your Favority Day?](https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/) | M | 本质上是两个区间能否匹配的问题。具体地，指定日期能吃多少糖的区间 是否能和 最喜欢类别的糖的最大最小区间存在重叠区域。 [Python](https://github.com/codename1995/leetcodehub/blob/master/python/WC226_03_Can_You_Eat_Your_Favorite_Candy_On_Your_Favorite_Day.py) |
|2021/01/24|WC225_01|[Latest Time by Replacing Hidden Digits](https://leetcode-cn.com/problems/latest-time-by-replacing-hidden-digits/)| E | 简单但错了两次，小时分钟时间表的hh部分，因为最大值为23，所以两位互有限制|
||WC225_02|[Change Minimum Characters to Satisfy One of Three Conditions](https://leetcode-cn.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/) | M | 三种情况都算一下然后取最小值即可|
||WC225_03|[Find Kth Largest XOR Coordinate Value](https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value/) | M| 简单累计矩阵问题，知道异或的两条规则即可： </br> A^A=0, 0^A=A
|2021/01/17|WC224_01|[Number Of Rectangles That Can Form The Largest Square](https://leetcode-cn.com/problems/number-of-rectangles-that-can-form-the-largest-square/)| E | 比较简单，直接 collections.Counter() 即可|
||WC224_02|[Tuple with Same Product](https://leetcode-cn.com/problems/tuple-with-same-product/)|M| 标题其实已经给了暗示！！！ </br> 1. 以计数器统计所有积出现的次数 </br> 2. 对出现超过两次的积，进行计算
||WC224_03| [Largest Submatrix With Rearrangements](https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements/)|M| 看到布尔矩阵，优先想是不是用累加矩阵求解。本题思路：1.统计原矩阵每个位置处是这一列自上而下的第几个连续的1；2.按行计算，先降序排列，然后逐元素计算，若以这一元素为长方形右下角顶点，则此时面积为多少|
|2021/01/10|WC223_03|[Minimize Hamming Distance After Swap Operations](https://leetcode-cn.com/problems/minimize-hamming-distance-after-swap-operations/)| M | [Python](https://github.com/codename1995/leetcodehub/blob/master/WeeklyContest/WCPython/WC223_03_Minimize_Hamming_Distance_After_Swap_Operations.py) 并查集典型应用|
||WC223_01|[Decode xored array](https://leetcode-cn.com/problems/decode-xored-array/) |E| a xor b = c </br> 异或的逆运算： </br> Python: a = - ( ~(c xor b) + 1)
|2020/04/19|WC185_04|[Build Array Where You Can Find The Maximum Exactly K Comparisons](https://leetcode-cn.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/) |H| [C++](https://github.com/codename1995/leetcodehub/blob/master/WeeklyContest/WCCPP/WC185_04_Build_Array_Where_You_Can_Find_The_Maximum_Exactly_K_Comparisons/WC185_04_Build_Array_Where_You_Can_Find_The_Maximum_Exactly_K_Comparisons.cpp) 三维动态规划|
|2020/04/12|WC184|第二次全A，但是是因为题目比较简单|||
||WC184_03|[HTML entity parser](https://leetcode-cn.com//problems/html-entity-parser/)|M|转义字符不熟悉|
||WC184_04|[Number of ways to paint nx3 grid](https://leetcode-cn.com/problems/number-of-ways-to-paint-n-x-3-grid/)|H|简单奥数题，属于想到很简单，想不到就做不来。稍微卡我的地方的大数操作又不记得了。
|2020/03/29|WC182|前三题比较顺利，第四题太难，只有不到40人完成|
|2020/03/22| WC181_01| [Create Target Array In The Given Order](https://leetcode-cn.com/problems/create-target-array-in-the-given-order/) |E| 关键语法：</br> PY: list.insert(ix,val)</br>CPP: v.insert(v.begin()+ix,val) |
||WC181_02| [Four divisors](https://leetcode-cn.com/problems/four-divisors/) | M|暴力，代码太丑，不贴了|
||WC181_03 |[Check If There Is A Valid Path In A Grid](https://leetcode-cn.com/contest/check-if-there-is-a-valid-path-in-a-grid/) |M| [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/WC181_03_Check_If_There_Is_A_Valid_Path_In_A_Grid/WC181_03_Check_If_There_Is_A_Valid_Path_In_A_Grid.cpp)</br>s.substr(ix)返回索引ix至结尾的子字符串 |
|2020/03/01| WC178_01 |[How Many Numbers Are Smaller Than The Current Number](https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number/) |E| [C++](https://github.com/codename1995/leetcodehub/blob/master/WeeklyContest/WCCPP/WC178_01_How_Many_Numbers_Are_Smaller_Than_The_Current_Number/WC178_01_How_Many_Numbers_Are_Smaller_Than_The_Current_Number.cpp) </br>解法1：暴力双层循环</br>解法2：先建积分表，再查询生成答案 |
||WC178_02 | [Rank Teams By Votes](https://leetcode-cn.com/problems/rank-teams-by-votes/) |M| [C++](https://github.com/codename1995/leetcodehub/blob/master/WeeklyContest/WCCPP/WC178_02_Rank_Teams_By_Votes/WC178_02_Rank_Teams_By_Votes.cpp) |
||WC178_03 |[Linked List In Binary Tree](https://leetcode-cn.com/problems/linked-list-in-binary-tree/) | M|[C++](https://github.com/codename1995/leetcodehub/blob/master/WeeklyContest/WCCPP/WC178_03_Linked_List_In_Binary_Tree/WC178_03_Linked_List_In_Binary_Tree.cpp) |
||WC178_04| 没看
|2020/01/12| [WC171](https://leetcode-cn.com/contest/weekly-contest-171)| 这次还是懒得贴 |||
||WC171_03 | [Number Of Operations To Make Network Connected](https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/) | M |[Python](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCPython/WC171_03_Number_Of_Operations_To_Make_Network_Connected.py)|
|2019/12/22| [WC168](https://leetcode-cn.com/contest/weekly-contest-168)| 这次依旧懒得贴 |||
||WC168_04| [你能从盒子里获得的最大糖果数 Maximum Candies You Can Get From Boxes](https://leetcode-cn.com/problems/maximum-candies-you-can-get-from-boxes/) |H| [C++](https://github.com/codename1995/leetcodehub/blob/master/WeeklyContest/WCCPP/WC168_04_Maximum_Candies_You_Can_Get_From_Boxes/WC168_04_Maximum_Candies_You_Can_Get_From_Boxes.cpp) |
|2019/12/15| [WC167](https://leetcode-cn.com/contest/weekly-contest-167/) | 这次也懒得贴了
||WC167_04|[网格中的最短路径 Shortest Path in a Grid with Obstacles Elimination](https://leetcode-cn.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/) | H| [C++](https://github.com/codename1995/leetcodehub/blob/master/WeeklyContest/WCCPP/WC167_04_Shortest_Path_In_A_Grid_With_Obstacles_Elimination/WC167_04_Shortest_Path_In_A_Grid_With_Obstacles_Elimination.cpp) DP+BFS|
|2019/12/08| [WC166](https://leetcode-cn.com/contest/weekly-contest-166/) | 这次懒得贴了
|2019/12/01| WC165 |[找出井字棋的获胜者 Find Winner on a Tic Tac Toe Game](https://leetcode-cn.com/problems/find-winner-on-a-tic-tac-toe-game/) | E | 模拟法，没啥价值，不贴了 |
|||[不浪费原料的汉堡制作方案 Number of Bugers with no Waste of Ingredients](https://leetcode-cn.com/problems/number-of-burgers-with-no-waste-of-ingredients/) | M | 鸡兔同笼问题，没啥价值，不贴了 |
|||[统计全为1的正方形子矩阵 Count Square Submatrices with All Ones](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/)| M | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC165_03_Count_Square_Submatrices_With_All_Ones/WC165_03_Count_Square_Submatrices_With_All_Ones.cpp)
|||[分割回文串 III Palindrome Partitioning III](https://leetcode-cn.com/problems/palindrome-partitioning-iii/) | H | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC165_04_Palindrome_Partitioning_III/WC165_04_Palindrome_Partitioning_III.cpp)
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

### 经验
#### 刷题经验
##### 第一题
1. 数据量较小时，考虑Brute-force

##### 第二题
1. 做完第一题时，看一下第二题和第三题的通过率，优先做通过率高的

##### 第三题
1. 做完第二题时，看一下第四题通过率如何，如果通过率较高，优先做第四题

#### 个人进步
**目前的流程：**
* 刷题
* 复盘

这样只能维持当前的水平缓慢下降，无法提升自己的水平

**更合理的流程：**
* 完整的学习-->建立知识体系
* 刷题+复盘-->查漏补缺

### 周赛流水账
#### BiWC70
Almost finish all questions. I was debugging the 3rd question at the last minute of the contest. And I finished it 5 minutes after the contest.

#### BiWC52
长时间不刷题，可能这次的题对Python比较友好，差点四题都对了，最后一题晚了8分钟，可惜！

#### WC227
这周的第一名用了4分钟解决前三题，而我用了77分钟。其中第三题做了50分钟，因为对问题的思考不够深入。如果能像第一名一样看穿问题的本质，代码其实很简短。


#### WC226
感觉最近思维速度下降了好多呀。思考第三题的边界的时候想了半天，幸好最后稀里糊涂想出来了，不然排名会很难看。
一个建议是，**如果题目里给了一个比较复杂的组合变量，那调用时用具体的名称会比用索引更直观**。
可以参考一下本次第三题的代码。

#### WC225
**第二题** 一直卡最后一个case，还以为是什么巨难的case，其实还是边界条件没有思考清楚

#### WC185
好长时间不刷题，只做周赛，所以能力下降得很明显，主要是对C++和Python很多基础语法都不熟悉了。
这次一三题20分钟，第二题题目太长懒得看，第四题做了两三个小时。
第四题自己的代码（不保存了，真想看去LC提交记录里看吧）主要错在dp[h][v][c]的定义和递推式，我把v定义为第h个字符的取值，这是错误的，因为你没法确定之前值的最大值是多少，也就知道h处取v是否增大。
合理的定义是dp[cur_length][cur_max_value][cost]，详细看代码吧。这题真的应该做出来的。

#### WC178
第一题，教训是**能暴力求解就暴力求解**，因为暴力的思路很简单，能够快速做出来，在时间复杂度或空间复杂度有要求的情况下，再进一步优化。
#### WC171
基本上，做出两题就是前1/3的位置
第一题，将整数转换为两个无零整数的和
* 按位遍历，求第一个整数对应位，并且以第二个整数该位不为零为约束
  * 该位为零，则分配1，且高位退位
  * 该位位一，则分配2（若分配1，则第二个整数有零了），且高位退位
  * 其他，则分配1
* 最终返回第一个整数，与输入数减第一个整数

第二题 或运算的最小翻转次数
逐位运算，注意条件清晰即可

第三题 连通网络的操作次数
涉及并查集的初始化，插入新的并查集，合并并查集，更新指定并查集等操作


#### WC168
第一题秒。
第二题python超时，但是C++的map用的很**不熟练**
第三题没做
第四题是模拟解法，花点时间就能做出来，但是第二题耽误了太多时间，第四题debug的时间不足。到本地IDE后发现，只是一处判断条件出现了笔误。简单但致命。
**想要避免这类问题的重演，应该**
* 强化人脑debug
* 搭建一个类似Leetcode输入的本地测试框架

#### WC167
前两题16分钟AC，然而第一名已经通关了。。。
这不重要！
第三题在第60分钟做完，现在基本稳定输出三题了！
**第四题**比较难，赛后又花了一个半小时。一开始写的DFS超时，这题还是得用BFS+不完全DP。
* `[r,c,z]`入队，分别表示横纵坐标和当前经过障碍
* `[r,c,z]`出队时，判断它四邻域是否需要更新，判断条件为：1）不越界；2）不超出可消除障碍数`k`；3）更新后值更小
* 若需要更新，则新点入队
* 最后在dp[m-1][n-1][0...k]中找最小值

**递推公式：** dp[r][c][k] = min(dp[四邻域][k]+1) if g[r][c]==0 else min(dp[四邻域][k-1]+1)
这是超级大佬@liaozhou_101 的解法，解读之后觉得非常精妙，不知道自己能不能举一反三。
#### WC166
前两题直接AC了，并且思路和晒出来的思路基本一致，就略了
第三题，TLE了，看了别人的提示，用二分法错了五次才过。
**重点：单调函数考虑二分法！！**
第四题，由于格子数少，可以暴力做。

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
经验教训就是一定不要贪多，循序渐进稳扎稳打，**123题一道一道做**。

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
|BiWC70|1537/17655|**8.7%**|
|BiWC69|2961/15120|19.6%|
|BiWC52|2542/10364|24.5%|
|WC227 |724/3545 |20.4%|
|WC226 |968/4033 |24.0%|
|WC225 |1328/3851 |34.5%|
|WC224 |607/3794 |16.0%|
|WC223 |1394/3870 |36.0%|
|WC222 |547/3117 |17.5%|
|WC221 |1003/3397 |29.5%|
|WC185 |956/5001  |19.1%|
|WC184 |350/3846  |9.1%|
|WC182 |735/3910  |18.8%|
|WC181 |591/4148  |14.2%|
|WC178 |597/3304  |17.7%|
|WC171 |617/1707  |36.1%|
|WC168 |571/1551  |36.8%|
|WC167 |220/1534  |14.3%|
|WC166 |452/1675  |27.0%|
|WC165 |312/1659  |18.8%|
|WC164 |145/1674  |**8.7%**|
|WC163 |1500/1604 |93.5%|
|WC162 |451/1568 |28.8%|
|WC160 |207/1691 |12.2%|
|WC159 |539/1633 |33.0%|