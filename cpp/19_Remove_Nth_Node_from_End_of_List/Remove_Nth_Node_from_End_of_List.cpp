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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		// 《剑指offer》提出了三个异常，但在lc的测试样例中主动避免了这些问题，在此列出
		// 1. head为空指针
		// 2. n==0
		// 3. n<链表长度
		ListNode* real_head = new ListNode(0); // use virtual head to cover situation that delete head node
		real_head->next = head;
		ListNode* s = real_head;
		ListNode* f = real_head;

		int cnt = 0;
		while (f && cnt < n)
		{
			// This loop let the gap between f ans s be n
			f = f->next;
			cnt++;
		}

		while (f->next)
		{
			
			f = f->next;
			s = s->next;
		}
		// when out of loop, s stay at the node before to-be-deleted node 
		s->next = s->next->next;

		return real_head->next;

	}
};