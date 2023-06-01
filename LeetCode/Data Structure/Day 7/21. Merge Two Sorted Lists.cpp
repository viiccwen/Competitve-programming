class Solution {
public:
    /*void Print(ListNode* pre_list1, ListNode* list2) {
        ListNode* test1 = pre_list1;
        ListNode* test2 = list2;
        cout << '\n';
        while (test1 != nullptr) {
            cout << test1->val << ' ';
            test1 = test1->next;
        }
        cout << '\n';
        while (test2 != nullptr) {
            cout << test2->val << ' ';
            test2 = test2->next;
        }
        cout << '\n';
    }*/
    void SwapList(ListNode*& list1, ListNode*& list2) {
        ListNode* temp = list1;
        list1 = list2;
        list2 = temp;
    }
    void InsertNode(ListNode*& ptr1, ListNode*& ptr2) {
        ListNode* temp = new ListNode;
        temp->val = ptr2->val;
        temp->next = ptr1->next;
        ptr1->next = temp;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        // swap
        if (list2->val < list1->val) SwapList(list1, list2);

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        bool flag = false;

        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->next == nullptr && ptr2 != nullptr) {
                ptr1->next = ptr2;
                //Print(pre_list1, list2);
                break;
            }
            else if (ptr2->val >= ptr1->val && ptr2->val < ptr1->next->val) {
                InsertNode(ptr1, ptr2);
            }
            else {
                ptr1 = ptr1->next;
            }

            //Print(pre_list1, list2);

        }
        return list1;
    }
};