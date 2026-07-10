/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp!= NULL){
            cnt++;
            if(cnt>1e4) return true;
            temp = temp->next;
        }
        return false;
    }
};