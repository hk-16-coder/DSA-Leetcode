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
    void generate(TreeNode* root , string s , vector<string>& res){
        if(root == NULL) return;
        s = s + to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            res.push_back(s);
            return ;
        }
        
        generate(root->left , s , res);
        generate(root->right , s , res);
    }
    int sumNumbers(TreeNode* root) {
        vector<string> res;
        string s = "";
        int sum = 0;
        
        generate(root,s,res);
        for(int i = 0 ; i<res.size() ; i++){
            sum+=stoi(res[i]);
        }

        return sum;
    }
};