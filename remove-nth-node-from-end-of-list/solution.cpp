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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        int k = cnt-n+1;
        if(k==1){
             head = head->next;
             return head;
             }
        temp = head;
        cnt = 0;
        ListNode* prev = NULL;
        while(temp){
            cnt++;
            if(cnt==k){
                prev->next = prev->next->next;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};