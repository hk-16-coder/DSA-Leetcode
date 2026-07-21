/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Write a root to node path for both the modes and then compare them
        vector<TreeNode*> arr1,arr2;
        getPath(root,arr1,p);
        getPath(root,arr2,q);

        int i=0,j=0;
        TreeNode* ans = NULL;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i] == arr2[j]) ans = arr1[i];
            i++;
            j++;
        }
        return ans;
    }
    bool getPath(TreeNode* root , vector<TreeNode*>& arr , TreeNode* x){
        if(root == NULL) return false;
        arr.push_back(root);

        if(root == x) return true;
        if(root->val > x->val) {
            if(getPath(root->left,arr,x)) return true;
            }
        else if(root->val < x->val){ 
            if(getPath(root->right,arr,x)) return true;
        }

        arr.pop_back();
        return  false;
    }
};