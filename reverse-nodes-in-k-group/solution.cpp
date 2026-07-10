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
        if(head->next == NULL || k == 1) return head;
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        int reversals = cnt/k;
        ListNode* curr = head;
        ListNode* prevTail = NULL;
        ListNode* newHead = NULL;
        for(int i = 0 ; i<reversals ; i++){
            ListNode* grpHead = curr; 
            ListNode* prev = NULL;

            for(int i = 0 ; i<k ; i++){
                ListNode* nextNode = curr->next;
                curr->next = prev;

                prev = curr;
                curr = nextNode;
            }
            if(newHead == NULL) newHead = prev;
            if(prevTail) prevTail->next = prev;

            grpHead->next = curr;
            prevTail = grpHead;
        }
        return newHead;
    }
};