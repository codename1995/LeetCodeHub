LeetCodeHub
===========================
LeetCode solution (C++ and Python)

- [LeetCodeHub](#leetcodehub)
- [TODO](#todo)
- [Leetcode Hot & Top](#leetcode-hot--top)
- [Sort by coding-interview (剑指offer)](#sort-by-coding-interview-%e5%89%91%e6%8c%87offer)
- [Tag](#tag)

# TODO
* [x] 1. 《剑指offer》习题一刷 (19年11月10日完成)
   * 十分钟思考
   * 想不出来直接看解答，然后自己实现
* [ ] 2. 按Tag整理习题
   * 对常用的数据结构、方法、套路进行整理
* [ ] 3. 《剑指offer》二刷
   * 注重一题多刷，多题一解
   * 一遍过的就不用在意
* [ ] 4. Leetcode [Hot 100](https://leetcode-cn.com/problemset/hot-100/) + [Top](https://leetcode-cn.com/problemset/top/) (1/144/245) (上传/完成/总数)
 
# Leetcode Hot & Top
| Leetcode  | Solution  | Basic idea   |
| ---       | ---       |  ---         |
| 337 [House Robber III](https://leetcode-cn.com/problems/house-robber-iii/ ) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/337_House_Robber_III/337_House_Robber_III.cpp) | 1. 树型DP，子函数返回{MaxWithCurrNode, MaxWithoutCurrNode} |

# Sort by coding-interview (剑指offer)
这里按照剑指offer的顺序整理了部分Leetcode的题目，方便直接在Leetcode上刷题。同时，也给出了每题能AC的解法，以C++为主。  
Most of leetcode links are based on @yanring's [REPO](https://gist.github.com/yanring/fd7c494616f99052d1fea3bc788cc800).

| 剑指offer | Leetcode | Solution |  
| --- | --- | --- | 
| 03 数组中重复的数字 | 287 [Find the Duplicate Number](https://leetcode-cn.com/problems/find-the-duplicate-number/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/287_Find_the_Duplicate_Number/Find_the_Duplicate_Number.cpp) |  
| 04 二维数组中的查找 | 240 [Search a 2D Matrix II](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/240_Search_a_2D_Matrix_II/Search_a_2D_Matrix_II.cpp)  |  
| 05 [替换空格](https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) |  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/coding_interview_05_ReplaceSpace/05_ReplaceSpace.cpp) | 
| 06 从尾到头打印链表|| 可参考 24. 反转链表|
|07 重建二叉树| 105 [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)| [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/105_Construct_Binary_Tree_from_Preorder_and_Inorder/Construct_Binary_Tree_from_Preorder_and_Inorder.cpp)|
|08 二叉树的下一个节点|510 [Inorder Successor in BST II](https://leetcode-cn.com/problems/inorder-successor-in-bst-ii/)| [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/510_Inorder_Successor_in_BST_II/Inorder_Successor_in_BST_II.cpp) |
|09 用两个栈实现队列   |  232 [Implement Queue using Stacks](https://leetcode-cn.com/problems/implement-queue-using-stacks/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/232_Implement_Queue_using_Stacks/Implement_Queue_using_Stacks.cpp)  |
| 09_02 用两个队列实现栈   |  225 [Implement Stack using Queue](https://leetcode-cn.com/problems/implement-stack-using-queues/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/225_Implement_Stack_using_Queue/Implement_Stack_using_Queue.cpp)<u>**两个栈实现队列，一个队列实现栈!!!**</u>  |
| 10 斐波那契数列  |509 [Fibonacci Number](https://leetcode-cn.com/problems/fibonacci-number/)   | [C++]()  |
| 11 旋转数组中的最小数字  | 153 [Find Minimum in Rotated Sorted Array](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/153_Find_Minimum_in_Rotated_Sorted_Array/Find_Minimum_in_Rotated_Sorted_Array.cpp)   |
| 12 矩阵中的路径  | 79 [Word Search](https://leetcode-cn.com/problems/word-search/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/79_Word_Search/Word_Search.cpp)  |
| 13 机器人的运动范围  |   | 可参考1219 黄金矿工，也是二维矩阵dfs搜索的问题，而且更难一些  |
| 14 剪绳子 | 343 [Interger Break](https://leetcode-cn.com/problems/integer-break/)   | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/343_Interger_Break/Interger_Break.cpp)  |
| 15 二进制中1的个数  | 191 [Number of 1 Bits](https://leetcode-cn.com/problems/number-of-1-bits/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/191_Number_of_1_Bits/Number_of_1_Bits.cpp)  |
||(Advanced) 338 [Counting_Bits](https://leetcode-cn.com/problems/counting-bits/)|[C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/338_Counting_Bits/338_Counting_Bits.cpp)|
| 16 数值的整数次方 | 50 [Pow(x, n)](https://leetcode-cn.com/problems/powx-n/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/50_Pow/Pow.cpp), Python   |
| 17 打印从1到最大的n位数 |   |   |
| 18 删除链表的节点  | 237 [Delete Node in a Linked List](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/237_Delete_Node_in_a_Linked_List/Delete_Node_in_a_Linked_List.cpp) [python](https://github.com/codename1995/LeetCodeHub/blob/master/python/237.DeleteNodeInALinkedList.py)  |
|   | 203 [Remove Linked List Elements](https://leetcode-cn.com/problems/remove-linked-list-elements/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/203_Remove_Linked_List_Elements/Remove_Linked_List_Elements.cpp)  |
| 18_02 删除链表中重复的节点  | 83 [Remove Duplicates from Sorted List](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/83_Remove_Duplicates_from_Sorted_List/Remove_Duplicates_from_Sorted_List.cpp)  |
| 19 正则表达式匹配  | 10 [Regular Expression Matching](https://leetcode-cn.com/problems/regular-expression-matching/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/10_Regular_Expression_Matching/Regular_Expression_Matching.cpp),[Python](https://github.com/codename1995/LeetCodeHub/blob/master/python/10.RegularExpressionMatching.py), adapted from [offical solution](https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode/)  |
| 20 表示数值的字符串  | 65 [Valid Number](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/65_Valid_Number/Valid_Number.cpp) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/65_Valid_Number/Valid_Number.cpp)  |
| 21 调整数组顺序使奇数位于偶数前面  |905 [Sort Array By Parity](https://leetcode-cn.com/problems/sort-array-by-parity/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/905_Sort_Array_by_Parity/Sort_Array_by_Parity.cpp)  |
| 22 链表中倒数第k个节点  |19 [Remove Nth Node From End of List](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/19_Remove_Nth_Node_from_End_of_List/Remove_Nth_Node_from_End_of_List.cpp) |
| 23 链表中环的入口节点  |142 [Linked List Cycle II](https://leetcode-cn.com/problems/linked-list-cycle-ii/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/142_Linked_List_Cycle_II/Linked_List_Cycle_II.cpp)  |
| 24 反转链表  |206 [Reverse Linked List](https://leetcode-cn.com/problems/reverse-linked-list/)| [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/206_Reverse_Linked_List/Reverse_Linked_List.cpp),[Python](https://github.com/codename1995/LeetCodeHub/blob/master/python/206.ReverseLinkedList.py)  |
| 25 合并两个排序的链表  |21 [Merge Two Sorted Lists](https://leetcode-cn.com/problems/merge-two-sorted-lists/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/21_Merge_Two_Sorted_Lists/Merge_Two_Sorted_Lists.cpp)  |
| 26 树的子结构  | 572 [Subtree of Another Tree](https://leetcode-cn.com/problems/subtree-of-another-tree/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/572_Subtree_of_Another_Tree/Subtree_of_Another_Tree.cpp)  |
| 27 二叉树的镜像  | 226 [Invert Binary Tree](https://leetcode-cn.com/problems/invert-binary-tree/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/226_Invert_Binary_Tree/Invert_Binary_Tree.cpp)  |
| 28 对称的二叉树  | 101 [Symmetric Tree](https://leetcode-cn.com/problems/symmetric-tree/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/101_Symmetric_Tree/Symmetric_Tree.cpp)  |
| 29 顺时针打印矩阵  | 54 [Spiral Matrix](https://leetcode-cn.com/problems/spiral-matrix/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/54_Spiral_Matrix/Spiral_Matrix.cpp)  |
| 30 包含min函数的栈  | 155 [Min Stack](https://leetcode-cn.com/problems/min-stack/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/155_Min_Stack/Min_Stack.cpp)  |
| 31 栈的压入、弹出序列  | 946 [Validate Stack Sequences](https://leetcode-cn.com/problems/validate-stack-sequences/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/946_Validate_Stack_Sequences/Validate_Stack_Sequences.cpp)  |
| 32 从上往下打印二叉树| 102 [Binary Tree Level Order Traversal](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)| [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/102_Binary_Tree_Level_Order_Traversal/Binary_Tree_Level_Order_Traversal.cpp)|
| 32_03 之字形遍历二叉树| 103 [Binary Tree Zigzag Level Order Traversal](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/submissions/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/103_Binary_Tree_Zigzag_Level_Order_Traversal/Binary_Tree_Zigzag_Level_Order_Traversal.cpp) |
| 33 二叉搜索树的后序遍历序列  | (Primer) 255 [Verify Preorder Sequence of a Binary Tree](https://leetcode-cn.com/problems/verify-preorder-sequence-in-binary-search-tree/submissions/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/255_Verify_Preorder_Sequence_of_a_Binary_Tree/Verify_Preorder_Sequence_of_a_Binary_Tree.cpp)  |
| 34 二叉树中和为某一值的路径  | 112 [Path Sum](https://leetcode-cn.com/problems/path-sum/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/112_Path_Sum/Path_Sum.cpp)  |
| 35 复杂链表的复制  | 138 [Copy List with Random Pointer](https://leetcode-cn.com/problems/copy-list-with-random-pointer/) | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/138_Copy_List_with_Random_Pointer/Copy_List_with_Random_Pointer.cpp)  |
| 36 二叉搜索树与双向链表  | (Primer) 426 [Convert Binary Search Tree to Sorted Doubly Linked List](https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/426_Convert_Binary_Search_Tree_to_Sorted_Doubly_Linked_List/Convert_Binary_Search_Tree_to_Sorted_Doubly_Linked_List.cpp) 光有思路不行，这题自己写比题解的简洁性差很多 |
| 37 序列化二叉树  | 297 [serialize and deserialize binary tree](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)  | [C++](https://github.com/codename1995/LeetCodeHub/blob/master/cpp/297_Serialize_and_Deserialize_Binary_Tree/Serialize_and_Deserialize_Binary_Tree.cpp)  |
| 38 字符串的排列  | 46 [Permutations (unique number)](https://leetcode-cn.com/problems/permutations/)  | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/46_Permutations/Permutations.cpp)  |
| | 47 [Permutations ii (perhaps duplicates)](https://leetcode-cn.com/problems/permutations-ii/) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/47_Permutations_II/Permutations_II.cpp) |
| | 51 [N Queens](https://leetcode-cn.com/problems/n-queens/) ||
| 39 数组中出现次数超过一半的数字 | 169 [majority element (appear over 1/2)](https://leetcode-cn.com/problems/majority-element/) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/169_Majority_Element/Majority_Element.cpp) | 
| | 229 [majority element ii (appear over 1/3)](https://leetcode-cn.com/problems/majority-element-ii/) |  |
| 40 最小的k个数| 215 [Kth Largest Element in an array](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)| [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/215_Kth_Largest_Element_In_An_Array/Kth_Largest_Element_In_An_Array.cpp) | 
| 41 数据流中的中位数 | 295 [Find Median From Data Stream](https://leetcode-cn.com/problems/find-median-from-data-stream/) |[C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/295_Find_Median_From_Data_Stream/Find_Median_From_Data_Stream.cpp) | 
| 42 连续子数组的最大和| 53 [Maximum  Subarray](https://leetcode-cn.com/problems/maximum-subarray/) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/53_Maximum_Subarray/Maximum_Subarray.cpp)|
| 43 1-n整数中1出现的次数| 233 [Number of Digit One](https://leetcode-cn.com/problems/number-of-digit-one/) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/233_Number_of_Digit_One/Number_of_Digit_One.cpp) | 
| *44 数字序列中某一位的数字|400 [Nth Digit](https://leetcode-cn.com/problems/nth-digit/) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/400_Nth_Digit/Nth_Digit.cpp) | 
| 45 把数组排成最小的数| 179 [Largest Number](https://leetcode-cn.com/problems/largest-number/)| [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/179_Largest_Number/Largest_Number.cpp), [Python](https://github.com/codename1995/LeetCodeHub/blob/master/python/179.LargestNumber.py)| 
| 46 把数字翻译成字符串| 91 [Decode Ways](https://leetcode-cn.com/problems/decode-ways/)| [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/91_Decode_Ways/Decode_Ways.cpp) |
| 47 礼物最大值| 64 [Minimum Path Sum](https://leetcode-cn.com/problems/minimum-path-sum/) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/64_Minimum_Path_Sum/Minimum_Path_Sum.cpp) | 
| 48 最长不含重复字符的子字符串|3 [Longest Substring without Repeating Characters](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)| [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/3_Longest_Substring_Without_Repeating_Characters/Longest_Substring_Without_Repeating_Characters.cpp) |
||159 [Longest Substring with At Most two Distinct Characters](https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/)| 直接套用340代码，将输入参数k改为默认2即可 |
||340 [Longest Substring with At Most two Distinct Characters](https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/)| [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/159_Longest_Substring_With_At_Most_Two_Distinct_Characters/Longest_Substring_With_At_Most_Two_Distinct_Characters.cpp)|
| 49 丑数| 263 [Ugly Number](https://leetcode-cn.com/problems/ugly-number/)|[C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/263_Ugly_Number/Ugly_Number.cpp)|
| |264 [Ugly Number II](https://leetcode-cn.com/problems/ugly-number-ii/)|[C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/264_Ugly_Number_II/Ugly_Number_II.cpp)|
| 50 第一个只出现一次的字符| 387 [First Unique Character in A String](https://leetcode-cn.com/problems/first-unique-character-in-a-string/) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/387_First_Unique_Character_in_A_String/First_Unique_Character_in_A_String.cpp) |
|50_02 字符流中第一个只出现一次的字符|| 剑指50和LC340的集合，过于简单，略（~~其实是因为LC上没找到~~）|
| 51 求数组中的逆序对的总数||与LC493思路基本一致|
|| (Advanced) 493 [Reverse Pairs](https://leetcode-cn.com/problems/reverse-pairs/)| [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/493_Reverse_Pairs/Reverse_Pairs.cpp) |
||(Advanced Advanced) 315 [Count of Smaller Numbers after Self](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/)|[C++] <!--(https://github.com/codename1995/leetcodehub/blob/master/cpp/315_Count_Of_Smaller_Numbers_After_Self/Count_Of_Smaller_Numbers_After_Self.cpp) -->|
| 52 两个链表的第一个公共节点|160 [Intersection of Two Linked Lists](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/160_Intersection_Of_Two_Linked_Lists/Intersection_Of_Two_Linked_Lists.cpp)|
| 53 在排序数组中查找数字| 34 [Find First and Last Position of Element in Sorted Array](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)| [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/34_Find_First_And_Last_Position_Of_Element_In_Sorted_Array/34_Find_First_And_Last_Position_Of_Element_In_Sorted_Array.cpp )|
| 54 二叉搜索树的第k大节点|230 [Kth Smallest Element In A Bst](https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/230_Kth_Smallest_Element_In_A_Bst/230_Kth_Smallest_Element_In_A_Bst.cpp) |
| 55 二叉树的深度|104 [Maximum Depth Of Binary Tree](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/ ) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/104_Maximum_Depth_Of_Binary_Tree/104_Maximum_Depth_Of_Binary_Tree.cpp) |
| 56_00 56题的前置 数组中只出现1次的那个数字| 136 [Single Number](https://leetcode-cn.com/problems/single-number/ ) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/136_Single_Number/136_Single_Number.cpp)  XOR for every single number|
| 56_01 数组中只出现1次的2个数字 |260 [Single Number III](https://leetcode-cn.com/problems/single-number-iii/) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/230_Single_Number_III/230_Single_Number_III.cpp) 1. XOR. 2. Split to two subarray.  3. XOR for two subarray, resepctively.
| 56_02 其他数字都出现三次的数字中唯一只出现一次的数字 | 137 [Single Number II](https://leetcode-cn.com/problems/single-number-ii/ ) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/137_Single_Number_II/137_Single_Number_II.cpp) SUM all and mod 3 for every single bit|
| 57 和为s的数字|1 [Two Sum](https://leetcode-cn.com/problems/two-sum/ ) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/1_Two_Sum/1_Two_Sum.cpp) |
| 57_02 和为s的连续正数序列|829 [Consecutive Numbers Sum](https://leetcode-cn.com/problems/consecutive-numbers-sum/ ) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/829_Consecutive_Numbers_Sum/829_Consecutive_Numbers_Sum.cpp) |
| 58_01 翻转单词顺序| 151 [Reverse Words In A String](https://leetcode-cn.com/problems/reverse-words-in-a-string/ ) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/151_Reverse_Words_In_A_String/151_Reverse_Words_In_A_String.cpp) |
| 58_02 左旋转字符串|189 [Rotate Array](https://leetcode-cn.com/problems/rotate-array/ ) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/189_Rotate_Array/189_Rotate_Array.cpp)  |
| 59_01 滑动窗口的最大值 | 239 [Sliding Window Maximum](https://leetcode-cn.com/problems/sliding-window-maximum/ ) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/239_Sliding_Window_Maximum/239_Sliding_Window_Maximum.cpp) |
| 59_02 队列的最大值|没找到||
| 60 n个骰子的点数|1155 [Number Of Dice Rolls With Target Sum](https://leetcode-cn.com/problems/number-of-dice-rolls-with-target-sum/ ) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/1155_Number_Of_Dice_Rolls_With_Target_Sum/1155_Number_Of_Dice_Rolls_With_Target_Sum.cpp)|
| 61 扑克牌中的顺子||模拟法，注意细节即可 ~~(其实还是因为没找到)~~|
| 62 圆圈中最后剩下的数字|没找到||
| 63 股票的最大利润|121 [Best Time To Buy And Sell Stock](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/ ) | [C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/121_Best_Time_To_Buy_And_Sell_Stock/121_Best_Time_To_Buy_And_Sell_Stock.cpp) |
| 64 求1+2+..+n||[C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/coding_interview_64_Accumulate/coding_interview_64_Accumulate.cpp) 照着敲了一下第一种方法；补充了一种利用逻辑断路来做的方法。|
| 65 不用加减乘除做加法||[C++](https://github.com/codename1995/leetcodehub/blob/master/cpp/coding_interview_65_Add/coding_interview_65_Add.cpp) |
| *66 构建乘积数组|||
| 67 把字符串转换成整数|||
| 68 树中两个节点的最低公共祖先|||

# Tag
按Tag整理常见解题思路。存放在[这里](https://github.com/codename1995/LeetCodeHub/tree/master/Tag)  
以VS Code + Markdown Perview Enhanced 打开会更好。

<!-- |   | [](https://leetcode-cn.com/problems/ | [C++](),[Python]()  | -->
<!-- [C++](),[Python]() -->
<!-- [](https://leetcode-cn.com/problems/) -->