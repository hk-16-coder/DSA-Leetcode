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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int cnt = 1;
        while(curr->next){
            if((curr->val > prev->val && curr->val > curr->next->val) ||
             (curr->val < prev->val && curr->val < curr->next->val)){

                // CRITICAL POINT
                critical.push_back(cnt);
             }

             prev = curr;
             curr = curr->next;
             cnt++;
        }
        if(critical.size() < 2) return {-1,-1};
        
        vector<int> ans(2,1e9);
        ans[1] = critical[critical.size()-1] - critical[0];
       
        for(int i = 0 ; i<critical.size() - 1 ; i++){
            ans[0] = min(ans[0] , critical[i+1] - critical[i]);
        }

        return ans; 
    }
};