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
    ListNode* reverseList(ListNode* head) {
		// recusive method
		// iterative method
		ListNode* curr = head;
		ListNode* prev = NULL;
		ListNode* nextTmp;
		while (curr != NULL) {
			nextTmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextTmp;
        }
		return prev;

    }
};