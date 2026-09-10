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
    int ans = 0;
    pair<int,int> dfs(TreeNode* node){
        if(node == NULL) return {0,0};
        pair<int,int>  left = dfs(node->left);
        pair<int,int> right  = dfs(node->right);
        int sum = left.first + right.first + node->val;
        int cnt = left.second + right.second + 1;
        
        if(sum/cnt == node->val) ans++;

        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int,int>p =  dfs(root);
        return ans;
    }
};