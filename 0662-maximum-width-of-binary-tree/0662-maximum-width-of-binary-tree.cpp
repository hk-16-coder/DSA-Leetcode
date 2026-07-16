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
    priority_queue<pair<int, __int128>> pq; // <level,index>
    void marking(TreeNode* root , __int128 index , int level){
        if(root == NULL) return;
        pq.push({level,index});
        marking(root->left , index<<1 , level+1);
        marking(root->right , (index<<1) + 1 , level+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        marking(root,1,0);
        //if(root->right == NULL && root->left == NULL) return 1;
        int max_level = pq.top().first;
        long long top_index = pq.top().second;
        pq.pop();
        __int128 max_width = 1;
        while(!pq.empty()){
            if(pq.top().first != max_level){
                max_level = pq.top().first;
                top_index = pq.top().second;
                pq.pop();
            }
            else{
                max_width = max(max_width ,top_index - pq.top().second + 1);
                pq.pop();
            }
        }
        return max_width;
    }
};