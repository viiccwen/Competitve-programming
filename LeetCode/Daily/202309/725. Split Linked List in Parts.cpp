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
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int len = 0;
    ListNode* cur = head;
    while (cur != nullptr) {
      len++;
      cur = cur->next;
    }

    vector<ListNode*> split_vec;
    cur = head;
    int node_num = len / k, rmd = len % k;

    for (int i = 0; i < k; i++) {
      int node_size = node_num + (rmd > 0);
      ListNode *cur_head = nullptr, *cur_tail = nullptr;

      for (int j = 0; j < node_size; j++) {
        if (cur_head == nullptr)
          cur_head = cur_tail = cur;
        else {
          cur_tail->next = cur;
          cur_tail = cur_tail->next;
        }

        if (cur != nullptr) cur = cur->next;
      }

      if (cur_tail != nullptr) cur_tail->next = nullptr;

      split_vec.push_back(cur_head);
      rmd = max(rmd - 1, 0);
    }

    return split_vec;
  }
};