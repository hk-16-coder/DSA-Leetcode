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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> hash;
        for(int i = 0 ; i<inorder.size() ; i++){
            hash[inorder[i]] = i;
        }
        TreeNode* root = build(postorder , 0 , postorder.size() - 1 , inorder , 0 , inorder.size() - 1 , hash);
        return root;
    }
    TreeNode* build(vector<int>& postorder , int postStart , int postEnd , vector<int>& inorder , int inStart , int inEnd , map<int,int>& hash){
        if(postStart>postEnd || inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inRoot = hash[root->val];
        int leftNum = inRoot - inStart; // number of elements on left

        root->left = build(postorder, postStart, postStart + leftNum - 1, inorder, inStart, inRoot - 1, hash);
        root->right = build(postorder, postStart+ leftNum , postEnd - 1 ,  inorder , inRoot + 1, inEnd , hash);

        return root;
    }
};