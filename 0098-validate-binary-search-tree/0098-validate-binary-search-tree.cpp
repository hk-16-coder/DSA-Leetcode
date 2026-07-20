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
    void gen_inorder(TreeNode*root , vector<int>& arr){
        if(root == NULL) return ;
        
        gen_inorder(root->left,arr);
        arr.push_back(root->val);
        gen_inorder(root->right,arr);
        return ;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        gen_inorder(root, inorder);
        
        for(int i = 1 ; i<inorder.size() ; i++){
            if(inorder[i] <= inorder[i-1]) return false;
        }
        return true;
    }
};