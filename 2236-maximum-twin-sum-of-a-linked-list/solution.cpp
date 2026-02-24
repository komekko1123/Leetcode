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
    int pairSum(ListNode* head) {
      ListNode* slow = head, *fast = head;
      stack<int> st;
      int ans = 0;
      while( fast != nullptr && fast->next != nullptr ){
        st.push(slow->val); 
        slow = slow->next;
        fast = fast->next->next;
      } // while
      while( ! st.empty() ){
        int temp = st.top();
        st.pop();
        ans = max(ans,temp+slow->val);
        slow = slow->next;
      } // while

      return ans;
    }
};
