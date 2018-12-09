/*83. Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates 
such that each element appear only once.

Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
*/

class RemoveDuplicatesfromSortedList83 {

public:
  // this is simiple
  ListNode* solve(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* curr = head;

    while (curr != NULL && curr->next != NULL) {
      ListNode* next = curr->next;
      while (next != NULL && next->val == curr->val)
        next = next->next;
      curr->next = next;
      curr = next;
    }
    return head;

  }

  void test()
  {
    ListNode * head;
    head = createList({1,1,2,3,3});
    cout << "input list : ";
    printList(head);
    cout << "list w/o duplicates : ";
    printList(solve(head));

  }

};
