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
private:
    ListNode* reverse(ListNode* ptr) {
        ListNode* pre = NULL;
        ListNode* nex = NULL;
        while(ptr) {
            nex = ptr->next;
            ptr->next = pre;
            pre=ptr;
            ptr=nex;
        }
        return pre;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode* dummy = head;
            
        while(slow) {
            if(dummy->val != slow->val)
                return false;
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
    }
};