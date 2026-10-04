class Solution {
public:
    void f(int x , int n , int k , vector<int>& temp , vector<vector<int>>& ans){
        if(k == 0){
            ans.push_back(temp);
            return;
        }
        if(x > n) return;

        temp.push_back(x);
        f(x+1 , n , k-1 , temp , ans);
        temp.pop_back();
        f(x+1 , n , k  , temp , ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(1 , n , k , temp , ans);
        return ans;
    }

};