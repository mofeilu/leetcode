/*143. Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes 
itself may be changed.

Example 1:
Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/


/* idea:
1) Find the middle point using tortoise and hare method.
2) Split the linked list into two halves using found middle point in step 1.
3) Reverse the second half.
4) Do alternate merge of first and second halves. 
*/
class ReorderList143 {

public:
  ListNode* reverse(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* tail = head;
    ListNode* ptr = head->next;
    while (ptr != NULL) {
      tail->next = ptr->next;
      ptr->next = head;
      head = ptr;
      ptr = tail->next;
    } 

    return head;

  }


  void solve(ListNode* head) {
    if (head == NULL || head->next == NULL) return;
    // first find middle pt
    ListNode* fast = head->next;
    ListNode* slow = head;
    while (fast != NULL && fast->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
    }
    // the node next of slow is the second half
    ListNode* half2 = slow->next;
    slow->next = NULL;

    ListNode* ptr2 = reverse(half2); // list 2

    ListNode* ptr1 = head; // list 1

    // now merge list1 and list2
    while (ptr1 != NULL && ptr2 != NULL) {
      ListNode* ptrTmp = ptr2; // node to be inserted
      ptr2 = ptr2->next;
      ptrTmp->next = ptr1->next;
      ptr1->next = ptrTmp;
      ptr1 = ptrTmp->next;
    }

  }

  void test()
  {
    ListNode* head;
    head = createList({1,2,3,4,5});
    cout << "origional list: ";
    printList(head);
    cout << "rearranged list: ";
    solve(head);
    printList(head);

    head = createList({1,2,3,4});
    cout << "origional list: ";
    printList(head);
    cout << "rearranged list: ";
    solve(head);
    printList(head);

  }

};
