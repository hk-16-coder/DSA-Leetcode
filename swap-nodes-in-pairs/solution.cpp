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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode*dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;


        while(prev->next && prev->next->next){
            ListNode* temp = prev->next;
            ListNode* front = temp->next;
        
            temp->next = front->next;
            front->next = temp;
            prev->next = front;
            prev = temp;
        }
        return dummy->next;
    }
};