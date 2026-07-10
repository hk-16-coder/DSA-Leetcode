class Solution {
public:
    
    bool check(int row , int col , int idx,  vector<vector<char>>& board, string& word){
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size()) return false;

        if(board[row][col] != word[idx]) return false;
        if(idx == word.size() - 1) return true;

        char temp  = board[row][col];
        board[row][col] = '0'; // to mark the cells previously visited

        bool flag = check(row+1,col,idx+1,board,word) ||
                    check(row-1,col,idx+1,board,word) ||
                    check(row,col+1,idx+1,board,word) ||
                    check(row,col-1,idx+1,board,word) ;
        
        board[row][col] = temp ; // setting it back to its original value for backtracking
        return flag;
    } 
        
       
    bool exist(vector<vector<char>>& board, string word) {
        int n = word.size();
        
        for(int i = 0 ; i<board.size() ; i++){
            for(int j = 0 ; j<board[0].size() ; j++){
                if(board[i][j] == word[0]) {
                    if(check(i,j,0,board,word) == true) return true;
                }
            }
        }
        return false;
    }
};