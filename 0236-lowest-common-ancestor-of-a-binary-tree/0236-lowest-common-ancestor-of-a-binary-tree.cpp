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
    bool getPath(TreeNode* root , vector<TreeNode*>& arr , TreeNode* x){
        if(root == NULL) return false;
        arr.push_back(root);

        if(root == x) return true;
        if(getPath(root->left , arr , x) || getPath(root->right , arr , x)) return true;

        arr.pop_back(); // backtracking
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1,arr2;
        getPath(root,arr1,p);
        getPath(root,arr2,q);

        int i = arr1.size()-1;
        int j = arr2.size()-1;
        while(i!=j){
            if(i>j){
                i--;
            }
            else j--;
        }
        while(i>=0 && j>=0){
            if(arr1[i] == arr2[j]) return arr1[i];
            i--;
            j--;
        }
        return root;
    }
};