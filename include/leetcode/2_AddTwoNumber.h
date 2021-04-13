
// * Definition for singly-linked list.
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_02 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }
        int overFlow = 0;
        ListNode *head = new ListNode(0);
        ListNode *start = head;
        int sum;
        while(l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + overFlow;
            l1->val = sum % 10;
            overFlow = sum / 10;
            start->next = l1;
            start = start->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            sum = l1->val + overFlow;
            l1->val = sum % 10;
            overFlow = sum / 10;
            start->next = l1;
            start = start->next;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            sum = l2->val + overFlow;
            l2->val = sum % 10;
            overFlow = sum / 10;
            start->next = l2;
            start = start->next;
            l2 = l2->next;
        }

        if (overFlow) {
            start->next = new ListNode(overFlow); 
        }
        start = head;
        head = head->next;
        delete start;
        return head;
    }
};