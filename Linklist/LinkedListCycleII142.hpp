/*142. Linked List Cycle II
Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

*/
class LinkedListCycleII142 {

public:
  // idea is still use fast and slow ptr, but there're some
  // math involved
  /* assume from head to cycle begin point the dist is x,
     the perimeter of the circle is M. 
     then by the time fast and slow ptr meet. slow ptr is n*M - x 
     dist away from begin of cycle point (n is the first integer that have
     n*M - x > 0 ).  so now, we need M - (n*M - x) = (n-1)*M + x more step
     for slow ptr to go back to circle begin point.  taking advange of this:
     we can assign another ptr at head, go equal speed as slow ptr, then then must
     eventually met at circle begin point
  */
  ListNode *solve(ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;
    ListNode* slow = head->next;
    ListNode* fast = slow->next;

    while (fast != slow) {
      if (fast == NULL || fast->next == NULL) return NULL;
      fast = fast->next->next;
      slow = slow->next;
    }

    // if we reach here, then there is a cycle
    ListNode* ptrA = head;
    ListNode* ptrB = fast;
    while (ptrA != ptrB) {
      ptrA = ptrA->next;
      ptrB = ptrB->next;
    } 

    return ptrA;
  }

  void test()
  {
    ListNode* head; int circleBeginId;
    head = createList({-1,2,4,-3,5,6,7});
    cout << "the list as input : ";
    printList(head);
    circleBeginId = 3; // node with value -3; 
    cout << "the designed circle begin node id is : " << circleBeginId << endl;
    ListNode* tail = head;
    while (tail->next != NULL) tail = tail->next;
    ListNode* cirBeg = head;
    for (int i=0; i<circleBeginId; ++i)
      cirBeg =cirBeg->next;
    tail->next = cirBeg;
    

    ListNode* ptr = solve(head);
    cout << "the node val that circle begins: " << ((ptr == NULL) ? "null" : to_string(ptr->val))  << endl;
  }

};

