class Solution {
public:
    bool check(int row , int col , vector<string>& board , int n){
        int temp_row = row;
        int temp_col = col;
        
        // left
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        // upper diagonal
        col = temp_col;
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        // lower diagonal
        row = temp_row;
        col = temp_col;
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        return true;
    }

    void solve(int col , vector<string>& board , int& ans , int n){
            if(col == n){
                ans++;
                return;
            }
            for(int row = 0 ; row<n ; row++){
                if(check(row,col,board,n)){
                    board[row][col] = 'Q';
                    solve(col+1,board,ans,n);
                    board[row][col] = '.';   // backtracking
                }
            }
    }
        int totalNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        int ans = 0;
        for(int i = 0 ; i<n ; i++) board[i] = s;
        solve(0,board,ans,n);

        return ans;
    }
};