struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//The number of nodes in each linked list is in the range [1, 100].
//0 <= Node.val <= 9

class Solution {
public:

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    // init
    ListNode* res = nullptr;
    ListNode* walker = nullptr;

    bool carry = false;
    // + O( max( numL1,numL2 ) ) (time)
    while (l1 || l2) {

      // init
      int sum = 0;

      // two sum
      if (l1) { sum += l1->val; l1 = l1->next; }
      if (l2) { sum += l2->val; l2 = l2->next; }
      if (carry) { ++sum; }

      // bool ctrl
      if (sum >= 10) { carry = true; }
      else { carry = false; }

      int val = sum % 10; // val to store

      // + O( max( numL1,numL2 ) ) (space)
      // new node
      if (res == nullptr) { res = new ListNode(val); walker = res; } // 1st case
      else { walker->next = new ListNode(val); walker = walker->next; }
    }

    // edge case
    if (carry) { walker->next = new ListNode(1); }

    return  res;
  }
};

