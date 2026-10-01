class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral(n , vector<int>(n));
        int top = 0;
        int left = 0;
        int bottom = n-1;
        int  right = n-1;
        int cnt = 1;
       while(top<=bottom && left<=right){
        // right
        for(int j = left ; j <= right ; j++){
            spiral[top][j] = cnt;
            cnt++;
            }
        top++;

        // down
        for(int i = top ; i <= bottom ; i++) {
            spiral[i][right] = cnt;
            cnt++;
        }
        right--;

        // left
       if(top<=bottom){ 
         for(int j = right ; j >= left ; j--) {
            spiral[bottom][j] = cnt;
            cnt++;
         }
        bottom--;
       }

        // up
        if(left<=right){
            for(int i = bottom ; i >= top ; i--) {
                spiral[i][left] = cnt;
                cnt++;
            }
        left ++;
        }
       }
        return spiral;
    }
};