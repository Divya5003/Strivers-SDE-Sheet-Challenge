/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* itr = head;
        Node* front = head;
        while(itr){
            front = front->next;
            Node* copy = new Node(itr->val);
            itr->next = copy;
            copy->next = front;
            itr = front;
        }
        itr = head;
        while(itr){
            if(itr->random)
                itr->next->random = itr->random->next;
            itr = itr->next->next;
        }
        Node* dummy = new Node(0);
        itr = head;
        Node* copy = dummy;
        while(itr){
            front = itr->next->next;
            copy->next = itr->next;
            itr->next = front;
            copy = copy->next;
            itr = itr->next;
        }
        return dummy->next;
    }
};