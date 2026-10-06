class Solution {
public:
    int f(int x , vector<vector<int>>& matrix){
        int n = matrix.size();
        int cnt = 0;
        int i = 0 , j = n-1;

        while(i<n && j>=0){
            if(matrix[i][j] <= x){
                cnt += j+1;
                i++;
            }
            else{
                j--;
            }
        }

        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        int l = matrix[0][0];
        int h = matrix[n-1][n-1];

        while(l < h){
            int mid = l + (h - l)/2;

            int cnt = f(mid , matrix); // COUNTS NUMBER LESS THAN EQUAL TO MID
            if(cnt >= k) h = mid;
            else l = mid+1 ;
        }
        
        return h;
    }
};