/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
          if(head==null)
        {
            return null;
        }
        ListNode t1 = head;
          ListNode t2 = head.next;
        
        while(t2!=null)
        {
           while(t2!=null&&t1.val == t2.val){
               t2 = t2.next;
           }
            if(t2 == null)t1.next = t2;
            else{
            t1.next = t2;
            t1 = t2;
            t2 = t2.next;
            }
        }
       
        return head;
	}
    }
