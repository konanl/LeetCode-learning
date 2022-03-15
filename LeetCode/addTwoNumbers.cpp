#include<ostream>
using namespace std;

/*
        ���������ǿյ�������ʾ�����Ǹ���������
        ����ÿλ���ֶ��ǰ�������ķ�ʽ�洢��,
        ����ÿ���ڵ�ֻ�ܴ洢һλ���֡�
        ���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
        ����Լ����������0֮�⣬����������������0��ͷ��
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
      