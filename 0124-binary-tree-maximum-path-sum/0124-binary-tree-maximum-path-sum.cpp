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
    int max_sum = INT_MIN;
    int pathSum(TreeNode* root){
        if(root == NULL) return 0;
        int leftSum = max(0 , pathSum(root->left));
        int rightSum = max(0 , pathSum(root->right));
        
        int sum = root->val + leftSum + rightSum;
        max_sum = max(max_sum , sum);
        return  max(root->val+ leftSum , root->val + rightSum) ;
    }
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return max_sum;
    }
};