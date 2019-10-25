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
        if (!head || !head->next) return head;
        ListNode *l, *r;
        l = head;
        r = head->next;
        while (r)
        {
            if (l->val == r->val && r->next)
                r = r->next;
            else if(l->val == r->val)
            {
                l->next = NULL;
                r = NULL;
            }
            else
            {
                l->next = r;
                l = l->next;
                r = l->next;
            }
        }
        return head;
    }
};