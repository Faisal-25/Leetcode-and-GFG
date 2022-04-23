the idea is to travel the linked list at once and apply the addfirst function and this is really the game changer peice of code`
[](http://)while (curr != null && idx >= n && idx <= m) {
ListNode forw = curr.next;
curr.next = null;
addFirst(curr);
curr = forw;
idx++;
}
​
if (idx > m) {
if (prev != null) {
prev.next = th;
tt.next = curr;
return head;
} else {
tt.next = curr;
return th;
}
}`