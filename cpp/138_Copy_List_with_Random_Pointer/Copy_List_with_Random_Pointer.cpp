#include<vector>
#include<iostream>
#include<cstring>

using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
*/
class Solution {
public:
	void copyNodes(Node* head)
	{
		Node* p = head;
		while (p)
		{
			Node* p2 = new Node();
			p2->next = p->next;
			p2->val = p->val;
			p2->random = NULL;

			p->next = p2;
			p = p2->next;
		}
	}
	void connectRandomPointer(Node* head)
	{
		Node* p = head;
		while (p)
		{
			Node* p2 = p->next;
			if (p->random)
				p2->random = p->random->next;
			p = p2->next;
		}
	}
	Node* splitLinkedList(Node* head)
	{
		Node* p = head;
		Node* c = head->next;
		while (p)
		{
			Node* p2 = p->next;
			if (p2->next) {
				p->next = p2->next;
				p = p->next;
				p2->next = p->next;
				p2 = p2->next;
			}
			else
			{
				p->next = NULL;
				p2->next = NULL;
				break;
			}
		}
		return c;
	}
	Node* copyRandomList(Node* head) {
		// 1. make a copy after every node : A->B->C->D to A->A'->B->B'->C->C'->D->D'
		// 2. make copy for "random pointer", for example, if A->R == C, than A'->R == (A->R)->next == C->next
		// 3. split the complete linked list to orignal list and copy
		if (!head) return head;

		copyNodes(head);
		connectRandomPointer(head);
		return splitLinkedList(head);
	}
};
void main()
{
	Node* head = new Node(-1, NULL, NULL);
	Solution solu;
	solu.copyRandomList(head);

}