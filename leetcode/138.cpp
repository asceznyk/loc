class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) return head;
    unordered_map<Node*,Node*> copyMap;
    Node* copy = new Node(head->val);
    Node* res = copy;
    Node* curr = head;
    copyMap[curr] = copy;
    while (curr->next != nullptr) {
      copy->next = new Node(curr->next->val);
      copyMap[curr->next] = copy->next;
      curr = curr->next;
      copy = copy->next;
    }
    copy = res;
    curr = head;
    while (copy != nullptr) {
      copy->random = copyMap[curr->random];
      copy = copy->next;
      curr = curr->next;
    }
    return res;
  }
};

