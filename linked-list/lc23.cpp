/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        for (ListNode* head : lists) {
            if (head) minHeap.push(head);
        }
        while (!minHeap.empty())  {
            curr->next = minHeap.top();
            curr = curr->next;
            minHeap.pop();
            if (curr->next) minHeap.push(curr->next);
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};

