/**
 * Definition for singly-linked list.
 * struct ListNode {``
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* prevGroupTail, ListNode* currGroupTail) {
        ListNode* nextGroupHead = currGroupTail->next;
        ListNode* prev = nextGroupHead;
        ListNode* oldHead = prevGroupTail->next;
        ListNode* curr = oldHead;
        while (curr != nextGroupHead) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        prevGroupTail->next = currGroupTail;
        return oldHead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* sentinel = new ListNode();
        sentinel->next = head;
        ListNode* prevGroupTail = sentinel;
        while (prevGroupTail) {
            ListNode* currGroupTail = prevGroupTail; 
            int i;
            for (i = 0; i < k && currGroupTail; i++) {
                currGroupTail = currGroupTail->next;
            }
            if (i < k || !currGroupTail) break;
            prevGroupTail = reverse(prevGroupTail, currGroupTail);
        }
        ListNode* result = sentinel->next;
        delete sentinel;
        return result;
    }
};

