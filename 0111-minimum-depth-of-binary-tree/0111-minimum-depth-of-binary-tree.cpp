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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int height = q.front().second;
            q.pop();

            if(node->left == NULL && node->right == NULL) return height+1;

            if(node->left){
                q.push({node->left,height+1});
            }
            if(node->right){
                q.push({node->right , height+1});
            }
        }
        return -1;
    }
};