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
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
       
        // if(root == NULL) return ans;

        // ans.push_back(root->val);
        
        // preorderTraversal(root->left);
        // preorderTraversal(root->right);
        // return ans;

        // iterative solution
        stack<TreeNode*> st;
        st.push(root);
        if(root == NULL)return ans;
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
        
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);

            ans.push_back(node->val);
        }
        return ans;
    }
};