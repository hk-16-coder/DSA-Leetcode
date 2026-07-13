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
     int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        int levels = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i<size ; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            levels++;
        }
        return levels;
    }
    bool isBalanced(TreeNode* root) {
        // we calculate depth of both the subtrees 
        TreeNode* node = root;
        if(root == NULL) return true;
        
          int left = maxDepth(root->left);
          int right = maxDepth(root->right);
          int diff = abs(left-right);
          if(diff>1)return false;
          
          bool flag1 = isBalanced(root->left);
          bool flag2 = isBalanced(root->right);
        return flag1 && flag2;
    }
};