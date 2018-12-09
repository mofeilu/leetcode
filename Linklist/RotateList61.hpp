/*61. Rotate List
Given a linked list, rotate the list to the right by k places, 
where k is non-negative.

Example 1:
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/


class RotateList61 {

public:
  // for this problem, we just need simple math
  ListNode* solve(ListNode* head, int k) {
    if (head == NULL || head->next == NULL) return head;
    int N = 0;
    ListNode* ptr = head;
    ListNode* tail = NULL;
    while (ptr != NULL) { ++N; tail = ptr; ptr = ptr->next;}
    // find the pos of the node before rotatated head
    int pos = N-1 - k%N; 
    
    ptr = head;
    for (int i=1; i<=pos; ++i)
        ptr = ptr->next;
    if (ptr->next == NULL) return head;

    ListNode* ret = ptr->next;
    tail->next = head;
    ptr->next = NULL;
    return ret;

  }

  void test()
  {
    ListNode* head; int k;
    head = createList({1,2,3,4,5});
    k = 2;
    cout << "input list :";
    printList(head);
    cout << " k = " << k << endl;
    cout << "rotated list : ";
    printList(solve(head,k));
    head = createList({0,1,2});
    k = 4;
    cout << "input list :";
    printList(head);
    cout << " k = " << k << endl;
    cout << "rotated list : ";
    printList(solve(head,k));

  }

};
