#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseListNode(struct ListNode* head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *prev = NULL;
    struct ListNode *cur = head;
    struct ListNode *next = NULL;
    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

struct ListNode* SwapPairListNode(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = NULL;
    struct ListNode* third = NULL;
    for (; cur != NULL && cur ->next != NULL; ) {
        next = cur->next;
        third = next->next;
        next->next = cur;
        cur->next = third;
        if (prev == NULL) {
            head = next;
        } else {
            prev->next = next;
        }
        prev = cur;
        cur = third;
    }
    return head;
}

struct ListNode* StepKNode(struct ListNode *head, int k)
{
    int step = 0;
    struct ListNode *P = head; 
    while(P != NULL && step < k) {
        P = P->next;
        step++;
    }
    return P;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if (head == NULL || head->next == NULL || k <= 1) {
        return head;
    }
    struct ListNode *prev = NULL;
    struct ListNode *cur = head;
    struct ListNode *kNode = StepKNode(cur, k - 1);
    struct ListNode *next_head = NULL;
    struct ListNode *temp = NULL;

    while (cur != NULL && kNode != NULL) {
        next_head = kNode->next;
        kNode->next = NULL;
        temp = reverseListNode(cur);
        if (prev == NULL) {
            head = temp;
        } else {
            prev->next = temp;
        }
        struct ListNode *rear = cur;
        rear->next = next_head;
        prev = rear;
        cur = next_head;
        kNode = StepKNode(cur, k - 1);
    }
    return head;
}

struct ListNode* oddEvenList(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *odd = head;
    struct ListNode *even = head->next;
    struct ListNode *evenHead = even;
    while (even != NULL && even->next != NULL) {
       odd->next = even->next;
       odd = odd->next;

       even->next = odd->next;
       even = even->next;
    }
    odd->next = evenHead;
    return head;
}