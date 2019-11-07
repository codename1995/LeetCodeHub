#include<vector>
#include<iostream>
#include<cstring>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		// 思路不难，双指针分别遍历两个链表，某一指针到结尾后从另一个链表的头结点继续往下移动
		// 如果有相交节点，则两个指针都会在换头之后相遇于第一个相交节点。
		if (!headA || !headB) return NULL;	// 这个判断很巧妙
		ListNode* a, * b;
		a = headA;
		b = headB;

		while (a != b)						// 循环条件和return搭配得很巧妙
		{
			a = a ? a->next : headB;
			b = b ? b->next : headA;
		}
		return a;							// 退出循环时，a、b指向相交节点或者都指向NULL，因此
											// 直接返回a即可
	}
};
