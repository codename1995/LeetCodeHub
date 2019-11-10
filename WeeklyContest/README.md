
# Weekly Contest Summayr

|Date|Contest|Problem|Complexity|Solution|
|---|---|---|---|---|
|2019/11/10| WC162 | [奇数值单元格的数目 Cells with Odd Values in a Matrix] |E|[Python](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCPython/WC162_01_Cells_with_Odd_Values_in_a_Matrix.py)|
|||[重构 2 行二进制矩阵 Reconstruct a 2-Row Binary Matrix]|M|[Python](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCPython/WC162_02_Reconstruct_a_2-Row_Binary_Matrix.py)|
|||[统计封闭岛屿的数目 Number of Closed Islands]|M|[C++](https://github.com/codename1995/LeetCodeHub/blob/master/WeeklyContest/WCCPP/WC162_03_Number_of_Closed_Islands/WC162_03_Number_of_Closed_Islands.cpp)|
||||H||

#### WC162
第一题和第二题直接模拟法，一开始还担心会有case过不了，后来发现想多了。  

第三题想套用之前的模板做，花了70分钟也没做出来，赛后花了20分钟理思路，10分钟就写好了。
其实，只需要2次DFS即可。
第一次从边缘的所有点进行四邻域DFS，将途径的所有陆地设为2.
第二次遍历整个数组，每次发现一个陆地，都CNT++，并且对这个陆地进行DFS，所有途径的陆地设为3.
直接返回CNT即可。
在最终的数组中，1仍是水没有变动，2是与边缘相接的陆地，3是封闭的岛。

#### Rank
WC162 451/1568 28.8%