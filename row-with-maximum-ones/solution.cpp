class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int max_cnt = -1;
        int idx = -1;
        for(int i = 0 ; i<m ; i++){
            int cnt1 = 0;
            for(int j = 0 ; j<n ; j++){
                if(mat[i][j] == 1) cnt1++;
            }
           if(cnt1>max_cnt) {max_cnt = cnt1; idx = i;}
        }
        vector<int> ans = {idx,max_cnt};
        return ans;
    }
};