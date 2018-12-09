/*86. Partition List
Given a linked list and a value x, partition it such that all 
nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes 
in each of the two partitions.

Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

class PartitionList86 {

public:

  ListNode* solve(ListNode* head, int x) {
    if (head == NULL || head->next == NULL) return head;
    // create dummy node for convinence
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

       // find first node that is no less than x
    ListNode* prev = dummy->next;
    ListNode* tail = dummy;// tail of nodes small than x

    while (prev != NULL && prev->val < x) {
      tail = prev;
      prev = prev->next;
    }

    if (prev == NULL) return dummy->next;

    while (prev->next != NULL) {
      if (prev->next->val < x) {
        // break link
        ListNode* curr = prev->next;
        prev->next = curr->next;
        // insert curr to head
        curr->next = tail->next;
        tail->next = curr;
        tail = curr;

      } else {
        prev = prev->next;
      }
    }

    return dummy->next; // exclude dummy node
  }

  void test()
  {
    ListNode* head; int x;
    head = createList({1,4,3,2,5,2}); 
    x = 3;
    cout << "input list : "; printList(head);
    cout << " x = " << x << endl;
    cout << "output list : "; printList(solve(head,x));

    head = createList({1,1}); 
    x = 2;
    cout << "input list : "; printList(head);
    cout << " x = " << x << endl;
    cout << "output list : "; printList(solve(head,x));
  }

};
