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
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr) return head;

        unordered_set<ListNode*> st;
        ListNode* ptr = head;
        while (ptr->next != nullptr) {
            if (!st.count(ptr)) {
                st.insert(ptr);
            }
            else if (st.count(ptr)) return ptr;

            ptr = ptr->next;
        }
        return nullptr;
    }
};

// https://ithelp.ithome.com.tw/articles/10223721
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* slow, * fast;
        slow = fast = head;
        while (fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                fast = head;
                if (fast == slow) return slow;
                while (1) {
                    fast = fast->next;
                    slow = slow->next;
                    if (fast == slow) return slow;
                }
            }

            if (fast == nullptr) return nullptr;
        }
        return nullptr;
    }
};
