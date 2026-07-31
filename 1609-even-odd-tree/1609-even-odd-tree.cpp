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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int prev;
            if(level%2 == 0) prev = 0;
            else prev = INT_MAX; 
            for(int i = 0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                if(level%2 == 0){
                    if(node->val%2 == 0 || node->val<=prev) return false;
                    else prev = node->val;
                }
                else{
                    if(node->val%2 == 1 || node->val>=prev) return false;
                    else prev = node->val;
                }
            }
            level++;
        }
        return true;
    }
};