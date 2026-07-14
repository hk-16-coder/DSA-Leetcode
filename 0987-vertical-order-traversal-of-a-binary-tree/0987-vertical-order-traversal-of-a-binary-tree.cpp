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
// {{col,row} , node->val}
    priority_queue<pair<pair<int,int> , int> , vector<pair<pair<int,int> , int>> , greater<pair<pair<int,int> , int>>> pq;

    void traversal(TreeNode* root , int col , int row){
        if(root == NULL)return;
        pq.push({{col,row} , root->val});

        traversal(root->left , col-1 , row+1);
        traversal(root->right , col+1 , row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        traversal(root,0,0);

        int col = pq.top().first.first;
        while(!pq.empty()){
            vector<int> temp;

            while(!pq.empty() && pq.top().first.first == col){
                temp.push_back(pq.top().second);
                pq.pop();
            }
            ans.push_back(temp);
            col = pq.top().first.first;
        }
        return ans;
    }
};