#include <iostream>
using namespace std;
/*
Definition of singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} 
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // res to ret
        ListNode* res = nullptr;
        // carry over tracker
        bool carryOver = false;

        // walkers
        ListNode* l1Walker = l1;
        ListNode* l2Walker = l2;
        ListNode* resWalker = nullptr;

        // main loop
        while( l1Walker != nullptr || l2Walker != nullptr )
        {
            // calc sum
            int adder1 = 0;
            if (l1Walker)
            {
                adder1 = l1Walker->val;
            }
            
            int adder2 = 0;
            if (l2Walker)
            {
                adder2 = l2Walker->val;
            }
            
            int sum = adder1 + adder2;
            
            // take care of prev carry-over
            if (carryOver)
            {
                ++sum;
            }
            
            if (sum >= 10)
            {
                sum -= 10;
                carryOver = true;
            }
            else
            {
                carryOver = false;
            }
          
            
            // make new res node
            if (!res)
            {
                res = new ListNode(sum);
                resWalker = res;
            }
            // make and walk res node
            else
            {
                resWalker->next = new ListNode(sum);
                resWalker = resWalker->next;
            }
            
            // Walk input ls's
            if (l1Walker)
            {
                l1Walker = l1Walker->next;
            }
            if (l2Walker)
            {
                l2Walker = l2Walker->next;
            }
            
        }

        if (carryOver)
        {
            resWalker->next = new ListNode(1);
        }
        
        
        return res;


    }
};


void print_LL(ListNode *node) {
    while(node != nullptr) {
        cout << node->val << " -> " ;
        node = node->next;
    }
    cout << endl;
}


int main() {
    
    ListNode *l1_3 = new ListNode(3); 
    ListNode *l1_2 = new ListNode(4, l1_3);
    ListNode *l1_1 = new ListNode(2, l1_2);
    cout << "LL1: ";
    print_LL(l1_1);
    
    ListNode *l2_3 = new ListNode(4); 
    ListNode *l2_2 = new ListNode(6, l2_3); 
    ListNode *l2_1 = new ListNode(5, l2_2);
    cout << "LL2: ";
    print_LL(l2_1);


    Solution s; 
    ListNode *result; 
    result = s.addTwoNumbers(l1_1, l2_1); 
    print_LL(result); 
       
    return 0; 
}
