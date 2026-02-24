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
    ListNode* reverseList(ListNode* head) {
      if( head == nullptr  || head->next == nullptr )
        return head;
      ListNode *pre = nullptr, *curr = head;
      while( curr != nullptr ){ // o o o 
        ListNode *last = curr->next;
        curr->next = pre; // p-| <-h l
        pre = curr;
        curr = last; // p h c
      } // while    
      return pre;
    }
};
