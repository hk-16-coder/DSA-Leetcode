class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> vertex;

        for(int i = 0 ; i<n ; i++){
            int cnt = 0;
            for(int j = 0 ; j<n ; j++){
                if(matrix[i][j]) cnt++;
            }
            vertex.push_back(cnt);
        }

        return vertex;
    }
};