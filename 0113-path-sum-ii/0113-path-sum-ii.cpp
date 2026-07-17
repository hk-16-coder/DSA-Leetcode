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
    vector<vector<int>> ans;
    void calculate(TreeNode* node , vector<int> temp ,int cur_sum , int target){
        if(node == NULL) return;
        cur_sum+=node->val;
        temp.push_back(node->val);
 
        if(node->left == NULL && node->right == NULL){
            if(cur_sum == target) ans.push_back(temp);
            return;
        }
       
        calculate(node->left , temp , cur_sum , target);
        calculate(node->right , temp , cur_sum , target);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        calculate(root , temp , 0 , targetSum);
        return ans;
    }
};