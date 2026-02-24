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
    ListNode* oddEvenList(ListNode* head) {
      if( head == nullptr || head->next == nullptr)
        return head;
      ListNode * prev = new ListNode(0, head); // dummy
      ListNode * slow = prev, *fast = head;
      while( fast != nullptr && fast->next != nullptr){
        slow->next = fast->next;
        slow = slow->next;
        fast->next = fast->next->next;
        slow->next = nullptr;
        if( fast->next != nullptr )
          fast = fast->next;
      } // while
     
     fast->next = prev->next;
     return head;
    } // 
};
