/*445. Add Two Numbers II
You are given two non-empty linked lists representing two 
non-negative integers. The most significant digit comes first 
and each of their nodes contain a single digit. Add the two numbers 
and return it as a linked list.

You may assume the two numbers do not contain any leading zero, 
except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, 
reversing the lists is not allowed.
Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/


class AddTwoNumbersII445 {

public:
    // add list of equal length
    ListNode* addEqualLenList(ListNode* l1, ListNode* l2, int & carry) {
      if (l1 == NULL) return NULL;
      if (l1->next == NULL) {
        int val = l1->val + l2->val;
        ListNode* ladd = new ListNode(val%10);
        carry = val/10;
        return ladd;
      }

      int carry1;
      ListNode* res = addEqualLenList(l1->next, l2->next, carry1);
      int val = carry1 + l1->val + l2->val;
      ListNode* head = new ListNode(val%10);
      head->next = res;
      carry = val/10;
      return head;
    }

    // idea, we can use recursion
    ListNode* solve(ListNode* l1, ListNode* l2) {
      // first calc the lenght of l1 and l2;
      int n1 = 0;  ListNode* p1 = l1;
      while (p1 != NULL) {++n1; p1=p1->next;}
      int n2 = 0;  ListNode* p2 = l2;
      while (p2 != NULL) {++n2; p2=p2->next;}

      ListNode* l1New = (n1 >= n2) ? l1 : l2;  // the long list
      ListNode* l2New = (n1 >= n2) ? l2 : l1;  // the short list
      // add leading zeros to shorter list
      for (int i=0; i< abs(n1 - n2); ++i) {
          ListNode* ptr = new ListNode(0);
          ptr->next = l2New;
          l2New = ptr;
      }
      
      int carry;
      ListNode* ret = addEqualLenList(l1New, l2New, carry);
      
      if (carry == 0) return ret;
      else {
         ListNode* head = new ListNode(1);
         head->next = ret;
         return head;
      }
    }

    void test()
    {
      ListNode* l1;
      ListNode* l2;
      ListNode* l3;
      l1 = createList({7,2,4,3});
      l2 = createList({5,6,4});
      l3 = solve(l1,l2);
      cout << "l1 = ";
      printList(l1);
      cout << "l2 = ";
      printList(l2);
      cout << "l1+l2 = ";
      printList(l3);

       l1 = createList({0});
      l2 = createList({7,3});
      l3 = solve(l1,l2);
      cout << "l1 = ";
      printList(l1);
      cout << "l2 = ";
      printList(l2);
      cout << "l1+l2 = ";
      printList(l3);
    }

};
