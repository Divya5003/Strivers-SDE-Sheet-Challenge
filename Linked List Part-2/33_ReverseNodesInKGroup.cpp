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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k <= 1)
            return head;

        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode* prev = start;
        ListNode* curr = start;
        ListNode* nxt = start;

        int count = 0;
        while(curr->next){
            count++;
            curr = curr->next;
        }

        while(count >= k){
            curr = prev->next;
            nxt = curr->next;
            for(int i=1; i<k; i++){
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next= nxt;
                nxt = curr->next;
            }
            prev = curr;
            count -= k;
        }
        return start->next;
    }
};