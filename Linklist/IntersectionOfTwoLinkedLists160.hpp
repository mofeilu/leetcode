
/*160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of
two singly linked lists begins.
For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
*/  



class IntersectionOfTwoLinkedLists160 {

public:
  // idea is simple, find difference of length, then compensate
  // the difference and loop
  ListNode *solve(ListNode *headA, ListNode *headB) {

    int NA = 0;
    int NB = 0;
    ListNode* ptrA = headA;
    ListNode* ptrB = headB;
    while (ptrA != NULL) {
      ++NA;  ptrA = ptrA->next;
    }
    while (ptrB != NULL) {
      ++NB;  ptrB = ptrB->next;
    }

    int offSet = NA - NB;
    ptrA = headA; ptrB = headB;
    if (offSet > 0) {
      for (int i=0;i<offSet; ++i)
        ptrA = ptrA->next;
    } else {
      for (int i=0;i<(-offSet); ++i)
        ptrB = ptrB->next;
    }

    while (ptrA != ptrB) {ptrA = ptrA->next; ptrB = ptrB->next;}
    return ptrA;
  }

  void test()
  {
    ListNode* headA = createList({1,2,3,4,5,6});
    ListNode* headB = createList({8,7});
    headB->next->next = headA->next->next;  // the common node is 3
    cout << "list A : "; printList(headA);
    cout << "list B : "; printList(headB);
    cout << "common list : "; printList(solve(headA, headB));

    headA = createList({1,2,3,4,5,6});
    headB = createList({8,7});
    cout << "list A : "; printList(headA);
    cout << "list B : "; printList(headB);
    cout << "common list : "; printList(solve(headA, headB));

  }

};
