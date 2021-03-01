/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (!l1 || !l2)
        {
            if (l1)
            {
                return l1;
            }
            
            return l2;
        }
        
    
        // res and 2 walkers
        ListNode* res = nullptr;
        ListNode* w1 = l1;
        ListNode* w2 = l2;
        
        // init res w/ smaller val
        if (l1->val <= l2->val)
        {
            res = l1;
        }
        else if (l1->val > l2->val)
        {
            res = l2;
        }

        // main loop
        while (w1 && w2)
        {
            if (w1->next && (w1->next)->val < w2->val)
            {
                w1 = w1->next;
                continue;
            }

            // w1's val smaller
            if (w1->next && (w1->next)->val >= w2->val)
            {
                // tmp var's
                ListNode* w1n = w1->next;
                ListNode* w2n = w2->next;

                // ins w2 val
                w1->next = w1;

                // walk and append
                w1 = w1->next;
                w1->next = w1n;

                w2 = w2n;
            }
        }

        return res;

    }
};
