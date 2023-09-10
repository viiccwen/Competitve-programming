/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;

    unordered_map<Node*, Node*> mp;

    Node* itr = head;
    while (itr != nullptr) {
      mp[itr] = new Node(itr->val);
      itr = itr->next;
    }

    itr = head;
    while (itr != nullptr) {
      mp[itr]->next = mp[itr->next];
      mp[itr]->random = mp[itr->random];
      itr = itr->next;
    }

    return mp[head];
  }
};