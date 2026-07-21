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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return build(preorder,idx,INT_MAX);
    }
    
    TreeNode* build(vector<int>& preorder , int &idx , int upperbound){
        if(idx == preorder.size() || preorder[idx]>upperbound) return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        // WHILE GOING LEFT THE UPPER BOUND IS NODE'S VALUE WHILE GOING RIGHT THE PREVIOUS BOUND IS TRANSFERRED
        root->left = build(preorder , idx , root->val);
        root->right = build(preorder , idx , upperbound);

        return root;
    }
};