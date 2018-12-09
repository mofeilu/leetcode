/*24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return 
its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, 
only nodes itself may be changed.
*/

class SwapNodesInPairs24 {

public:
  // idea is simple, alternate between odd nodes and even nodes
  ListNode* solve(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* ptrO = head; // Odd
    ListNode* ptrE = head->next;   // Even
    ListNode* ret = ptrE; // head of return
    ListNode* prev = NULL; 
    while (true) {

      // swap
      if (prev != NULL) prev->next = ptrE;
      ptrO->next = ptrE->next; ptrE->next = ptrO;
      prev = ptrO;
      
      // proceed
      ptrO = ptrO->next;
      if (ptrO == NULL) break; 
      ptrE = ptrO->next;
      if (ptrE == NULL) break;
    }

    return ret;
  }

  void test()
  {
    ListNode* head = createList({1,2,3,4});
    cout << "input list :";
    printList(head);
    cout << "swap pairs we have : ";
    printList(solve(head));

    head = createList({1,2,3});
    cout << "input list :";
    printList(head);
    cout << "swap pairs we have : ";
    printList(solve(head));

    head = createList({1,2});
    cout << "input list :";
    printList(head);
    cout << "swap pairs we have : ";
    printList(solve(head));

  }

};
