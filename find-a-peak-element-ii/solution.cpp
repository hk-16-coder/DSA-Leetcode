class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = m-1; // on rows
        while(low<=high){
            int mid = low + (high-low)/2;
            int maxi = -1;
            int idx = -1;
            for(int i =  0 ; i<n ; i++){
               if(mat[mid][i]>maxi) {
                maxi = mat[mid][i];
                idx = i;
               }
            }
               int up = -1;
               int down = -1;
               if(mid-1>=0) up = mat[mid-1][idx];
               if(mid+1<m) down = mat[mid+1][idx];
      
               if(mat[mid][idx] > up && mat[mid][idx] > down) return {mid,idx};
               else if (mat[mid][idx] < up) high = mid-1;
               else low = mid+1;
        }
        return {-1,-1};
    }
};