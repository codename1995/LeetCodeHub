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
    ListNode* removeElements(ListNode* head, int val) {
        /*
        A brute-force method, but easy to understand.

        We start from head node and solve problem step by step.
        case1: if head == NULL, then return
        case2: if head->val == val, then delete head recursively
        case3: normal mode (node is not either head or tail)
                find a node (curNode->val == val) and delete it (by prevNode)
        case4: if it is a tail node (curNode->next == NULL), then delete it and stop.

        */
        if (!head) return head; // case 1: head == NULL
        while(head->val == val) // case 2: if head->val == val, then delete head
        {
            if (head->next) head = head->next;
            else return NULL;
        }
        // initial curNode and prevNdoe
        ListNode *curNode, *prevNode;
        if (head->next)
        {
            prevNode = head;
            curNode = head->next;
        }
        else return head;
        // normal mode, delete node if (node.val == val && node->next != NULL)
        while (curNode->next)
        {
            if (curNode->val == val)
            {
                prevNode->next = curNode->next;
                delete curNode;
                curNode = prevNode->next;
            }
            else
            {
                prevNode = curNode;
                curNode = curNode->next;
            }
        }
        // case 4: if tail.val == val, then delete tail
        if (curNode->val == val) prevNode->next=NULL;
        return head;
    }
};