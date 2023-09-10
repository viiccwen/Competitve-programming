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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (right == 1) return head;

    ListNode* dummy = new ListNode();
    dummy->next = head;
    ListNode *L = dummy, *R;

    for (int i = 0; i < left - 1; i++) {
      L = L->next;
    }

    R = L->next;

    for (int i = left; i < right; i++) {
      ListNode* rev = R->next;
      R->next = rev->next;
      rev->next = L->next;
      L->next = rev;
    }
    return dummy->next;
  }
};