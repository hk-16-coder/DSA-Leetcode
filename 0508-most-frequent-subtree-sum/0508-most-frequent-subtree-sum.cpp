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
    long long sum(TreeNode* root){
        if(root == NULL) return 0;
    
        return sum(root->left) + root->val + sum(root->right);
    }
    void inorder(TreeNode* root , unordered_map<int,int>& mpp){
        if(root == NULL) return ;
        inorder(root->left , mpp);
        mpp[sum(root)]++;
        inorder(root->right , mpp);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        inorder(root,mpp);
        priority_queue<pair<int,int>> pq;

        for(auto it : mpp){
            pq.push({it.second,it.first});
        }
        int max_freq = pq.top().first;
        ans.push_back(pq.top().second);
        pq.pop();
        while(!pq.empty()){
            if(pq.top().first == max_freq){
                ans.push_back(pq.top().second);
                pq.pop();
            }
            else break;
        }
        return ans;
    }
};