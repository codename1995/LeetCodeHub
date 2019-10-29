#include<vector>
#include<cstring>
#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
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
	ListNode* findIntersection(ListNode* head)
	{
		ListNode* s = head;
		ListNode* f = head;

		while (f && f->next)
		{
			s = s->next;
			f = f->next->next;
			if (s == f)
				return s;
		}
		return NULL;
	}
	ListNode* detectCycle(ListNode* head) {
		//@LeetCode presents a better solution than coding-interview
		// 1. use 'slow' and 'fast' to find the intersection node, if not, then no cycle
		// 2. set 'ptr2' = intersection node, set 'ptr1' = head; they move forward at same speed.
		// They will meet at the "cycle entrance".

		if (!head) return head;

		ListNode* intersectionNode = findIntersection(head);
		if (intersectionNode == NULL)
			return NULL;

		ListNode* ptr1 = head;
		while (ptr1 != intersectionNode)
		{
			ptr1 = ptr1->next;
			intersectionNode = intersectionNode->next;
		}
		return ptr1;
	}
};