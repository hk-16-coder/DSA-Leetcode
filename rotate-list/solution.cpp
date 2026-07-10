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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* newHead = head;
        if(head == NULL || head->next == NULL || k==0) return head;
        int cnt = 0;
        while(temp->next){
            cnt++;
            temp = temp->next;
        }
        cnt++;  
        k = k%cnt;
        if(k == 0) return head;
        temp->next = head;
        int steps = cnt - k;
        ListNode* newTail = head;
        for(int i = 1; i<steps ; i++) newTail = newTail->next;
        
        newHead = newTail->next;
        newTail->next = NULL;
        
        return newHead;
    }
};