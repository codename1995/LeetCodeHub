#include<iostream>
#include<cstring>

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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) return head;
		ListNode* prev = head;
		ListNode* curr = prev->next;
		while (curr) {
			if (prev->val == curr->val) {
				prev->next = curr->next;
				curr = curr->next;
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
		return head;
	}
};