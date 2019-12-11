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
	 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		 int carry = 0;
		 ListNode* head = l1;
		 ListNode* curr = l1;
		 while (l1 && l2) {
			 int v1 = 0, v2 = 0;
			 if (v1) {
				 v1 = l1->val;
				 l1 = l1->next;
			 }
			 if (v2) {
				 v2 = l2->val;
				 l2 = l2->next;
			 }
			 curr->val = (v1 + v2 + carry) % 10;
			 carry = (v1 + v2 + carry) / 10;

			 if (l1 && l2) {
				 curr->next = l1;
				 curr = curr->next;
			 }
			 else if (!l1) {
				 curr->next = l2;
				 break;
			 }
			 else if (!l2) {
				 curr->next = l1;
				 break;
			 }
		 }

		 return head;
	 }
 };