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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> hash;
        for(int i = 0 ; i<inorder.size() ; i++){
            hash[inorder[i]] = i;
        }
        TreeNode* root = build(preorder , 0 , preorder.size()-1 , inorder , 0 , inorder.size()-1, hash);
        return root;
    }

    TreeNode* build(vector<int>& preorder , int preStart , int preEnd , vector<int>& inorder , int inStart , int inEnd , map<int,int>& hash){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = hash[preorder[preStart]];
        int leftNum = inRoot - inStart; // number of elements on left

        root->left = build(preorder, preStart+1, preStart + leftNum, inorder, inStart, inRoot - 1, hash);
        root->right = build(preorder, preStart+ leftNum + 1, preEnd ,  inorder , inRoot + 1, inEnd , hash);

        return root;
    }
};