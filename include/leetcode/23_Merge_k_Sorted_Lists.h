#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_23 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int N = lists.size();
        if (N == 0) {
            return NULL;
        }
        int K = N;
        while(K > 1) {
            int mid = (K + 1) / 2;  // 合并后的长度
            for (int i = 0; i < K / 2; ++i) {
                lists[i] = mdergeTwoLists(lists[i], lists[i + mid]);
            }
            K = mid;
        }
        return lists[0];
    }
private:
    ListNode* mdergeTwoLists(ListNode* LA, ListNode* LB)
    {
        if (LA == NULL) {
            return LB;
        }
        if (LB == NULL) {
            return LA;
        }
        ListNode* phead = new ListNode();
        ListNode* start = phead;
        while(LA != NULL || LB != NULL) {
            if (LA == NULL || (LB != NULL && LA->val >= LB->val)) {
                start->next = LB;
                LB = LB->next;
            } else {
                start->next = LA;
                LA = LA->next;
            }
            start = start->next;
        }
        start = phead->next;
        delete phead;
        return start;
    }
};