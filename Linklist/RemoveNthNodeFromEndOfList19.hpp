/*19. Remove Nth Node From End of List
Given a linked list, remove the n-th node from the end of list 
and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list
 becomes 1->2->3->5.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?
*/
class RemoveNthNodeFromEndOfList19 {

public:
  // we need one pass solution, idea is simple, first go to the nth node
  // from head, mark it, then move head node and mark node simultaneously 
  // until the mark node reach the end, now the head node would be the anwser
  ListNode* solve(ListNode* head, int n) {
    ListNode* ptr = head;
    for (int i=0; i<n; ++i) //
      ptr = ptr->next;
    if (ptr == NULL) { // we need to remove head
      head = head->next;
      return head;
    }


    ListNode* delPrev = head;  // the node before remove node
    while (ptr->next != NULL) {
      delPrev = delPrev->next;
      ptr = ptr->next;
    }
    
    delPrev->next = delPrev->next->next;
    return head;
  }

  void test()
  {
    ListNode * head; int n;
    head = createList({1,2,3,4,5});
    n = 2;
    cout << "input list : ";
    printList(head);
    cout << "n = " << n << endl;
    cout << "output lis : ";
    printList(solve(head,n));
  }

};
