/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long> , greater<long long>> pq;  //  MIN HEAP
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            level++;
            for(int i = 0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                sum+=1LL*node->val;
            }
            pq.push(sum);
            if(pq.size()>k) pq.pop();
        }
        if(level < k) return -1;
        return pq.top();
    }
};