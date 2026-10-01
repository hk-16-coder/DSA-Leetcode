class Solution {
public:
    bool helper(int i , int j , int x , vector<vector<char>>& board){
        char c = '0' + x;

        // row check
        for(int col = 0 ; col<9 ; col++){
            if(col != j && board[i][col] == c) return false;
        }

        // column check
        for(int row = 0 ; row<9 ; row++){
            if(row != i && board[row][j] == c) return false;
        }

        // square check
        int rowN = i/3;
        int colN = j/3;

        for(int row = 3*rowN ; row < rowN*3 + 3 ; row++){
            for(int col = 3*colN ; col < colN*3 + 3 ; col++){
                if(row != i && col != j && board[row][col] == c) return false;
            }
        }

        return true;
    }
    bool solve(int i , int j ,  vector<vector<char>>& board){
        if(j == 9){
            j = 0 ; i+=1;
        }
        if(i == 9) return true;
        if(board[i][j] != '.') return solve(i , j+1 , board);
        for(int num = 1 ; num<=9 ; num++){
            if(helper(i , j , num , board)){
                board[i][j] = '0' + num;
                if(solve(i , j+1 , board)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
       solve(0 , 0 , board); 
    }
};