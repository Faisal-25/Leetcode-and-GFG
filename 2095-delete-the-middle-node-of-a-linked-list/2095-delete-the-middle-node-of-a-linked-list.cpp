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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*prev = new ListNode(-1);
        prev->next = head;
        ListNode*dummy = prev;
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast != NULL && fast->next!=NULL){
            prev = prev->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return dummy->next;
    }
};