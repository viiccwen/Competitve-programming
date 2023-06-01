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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;

        ListNode* pre_ptr = new ListNode;
        pre_ptr->next = head;
        ListNode* ptr = pre_ptr;

        while (ptr->next != nullptr) {
            if (ptr->next->val == val) {
                ListNode* dump = ptr->next;
                ptr->next = ptr->next->next;
                delete dump;
            }
            else ptr = ptr->next;
        }

        return pre_ptr->next;
    }
};