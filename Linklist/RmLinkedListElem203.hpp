/*203. Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.

Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/
class RmLinkedListElem203 {
public:
  // idea: just use prev and curr ptr and iterate
  ListNode* solve(ListNode* head, int val) {
    ListNode* prev = head;
    // find first non val node
    while (prev != NULL && prev->val == val) { prev = prev->next;}
    if (prev == NULL) return prev;
    ListNode* ret = prev; // new head
    ListNode* curr = prev->next;
    while (curr != NULL) {
      if (curr->val == val) {
        curr = curr->next;
        prev->next = curr;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }

    return ret;
  }

  void test()
  {
    ListNode* head; int val;
    head = createList({1,2,6,3,4,5,6});
    val = 6;
    cout << "input list : ";
    printList(head);
    cout << "elem val to remove : " << val << endl;
    cout << "output list : ";
    printList(solve(head,val));

  }

};
