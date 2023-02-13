#include <iostream>
#include<string>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_92 {  
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }

        ListNode* leftPrevNode = NULL;
        ListNode* leftNode = head;
        ListNode* rigtNode = head;
        ListNode* rightNextNode = NULL;

        for (int i = 1; i < left; ++i) {
            leftPrevNode = leftNode;
            leftNode = leftNode->next;
        }

        rigtNode = leftNode;
        rightNextNode = rigtNode->next;
        for (int i = left; i < right; ++i) {
            rigtNode = rigtNode->next;
            rightNextNode = rigtNode->next;                                                                 
        }

        rigtNode->next = NULL;

        ListNode* newHead = reverseList(leftNode);
        if (leftPrevNode) {
            leftPrevNode->next = newHead;
        } else {
            leftPrevNode = newHead;
        }
        leftNode->next = rightNextNode;

        return leftPrevNode;
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = NULL;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};