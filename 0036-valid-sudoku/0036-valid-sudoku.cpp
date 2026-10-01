class Solution {
public:
    bool helper(int i , int j , char c , vector<vector<char>>& board){
        //char c = '0' + x;

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
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i<9 ; i++){
            for(int j = 0 ; j<9 ; j++){
                if(board[i][j] == '.') continue;
                if(!helper(i , j , board[i][j] , board)) return false;
            }
        }
        return true;
    }
};