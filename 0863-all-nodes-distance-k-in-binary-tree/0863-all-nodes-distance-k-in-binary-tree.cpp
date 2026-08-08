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
    int max_val = 0;
    void findMax(TreeNode* node ){
        if(node == NULL) return ;
        max_val = max(max_val,node->val);
        if(node->left) findMax(node->left);
        if(node->right) findMax(node->right);
    }

    void inorder(TreeNode* node , vector<vector<int>>& adj){
        if(node == NULL) return;
        if(node->left){
            adj[node->val].push_back(node->left->val);
            adj[node->left->val].push_back(node->val);
            inorder(node->left,adj);
        }
        if(node->right){
            adj[node->val].push_back(node->right->val);
            adj[node->right->val].push_back(node->val);
            inorder(node->right,adj);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findMax(root);
        int n = max_val;

        vector<vector<int>> adj(n+1);
        inorder(root,adj);

        queue<pair<int,int>> q ; // <node,steps>
        q.push({target->val , 0});

        vector<int> vis(n+1,0);
        vis[target->val] = 1;

        vector<int>ans;

        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(steps == k){
                ans.push_back(node);
                continue;
            }
            if(steps>k)continue;
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,steps+1});
                }
            }
        }
        return ans;
    }
};