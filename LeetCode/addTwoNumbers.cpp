#include<ostream>
using namespace std;

/*
        给你两个非空的链表，表示两个非负的整数。
        它们每位数字都是按照逆序的方式存储的,
        并且每个节点只能存储一位数字。
        请你将两个数相加，并以相同形式返回一个表示和的链表。
        你可以假设除了数字0之外，这两个数都不会以0开头。
*/
 //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution {
 public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* p1 = l1, * p2 = l2;
         ListNode* dummyHead = new ListNode(-1);
         ListNode* cur = dummyHead;

         int carried = 0;
         while (p1 || p2) {
             carried += (p1 ? p1->val : 0) + (p2 ? p2->val : 0);
             cur->next = new ListNode(carried % 10);
             carried /= 10;

             cur = cur->next;
             p1 = p1 ? p1->next : NULL;
             p2 = p2 ? p2->next : NULL;
         }
         cur->next = carried ? new ListNode(1) : NULL;
         ListNode* ret = dummyHead->next;
         delete dummyHead;
         return ret;
     }
 };
      