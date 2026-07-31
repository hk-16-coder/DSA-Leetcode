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
    int maxLevelSum(TreeNode* root) {
        int x = -1;
        int level = 0;
        int max_sum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            level++;
            for(int i = 0 ; i<size ; i++){
              TreeNode* node = q.front();
              q.pop();
              if(node->left) q.push(node->left);
              if(node->right) q.push(node->right);
              sum+=node->val;
            }
            if(sum>max_sum){
                max_sum = sum;
                x = level;
            }
        }
        return x;
    }
};