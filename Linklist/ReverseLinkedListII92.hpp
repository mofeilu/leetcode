/*92. Reverse Linked List II
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

class ReverseLinkedListII92 {

public:
  // idea: for nodes from m to n, keep moving it to the m-1
  // pos, keep links consistent
  ListNode* solve(ListNode* head, int m, int n) {
    if (m == n) return head;
    // for convinenice, add dummy node
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    // first find the node before m
    ListNode* ptr0 = dummy;
    for (int i=0; i<m-1; ++i)
      ptr0 = ptr0->next;

    // head and tail of m to n sublist 
    ListNode* tail1 = ptr0->next; 
    ListNode* head1 = ptr0->next;
    ListNode* curr = tail1->next;  
    int pos = m+1;
    while (pos <= n) {
      tail1->next = curr->next;
      curr->next = head1;
      head1 = curr;
      curr = tail1->next;
      ++pos;
    }

    ptr0->next = head1;

    return dummy->next;  // exclude dummy node
  }

  void test()
  {
    ListNode* head;
    int m,n;

    head = createList({1,2,3,4,5});
    m = 2; n = 4;  // 1 based index
    cout << "input list : ";
    printList(head);
    cout << "m = " << m << " n = " << n << endl;
    cout << "reversed list : ";
    printList(solve(head,m,n));

  }

};
