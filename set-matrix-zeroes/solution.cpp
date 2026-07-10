class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> rows;
        set<int> columns;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for(auto it : rows){
            for(int j = 0 ; j<n ; j++){
                matrix[it][j] = 0;
            }
        }
        for(auto it : columns){
            for(int j = 0 ; j<m ; j++){
                matrix[j][it] = 0;
            }
        }

       
    }
};