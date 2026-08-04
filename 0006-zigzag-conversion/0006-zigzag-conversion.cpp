class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int size = s.size();
        vector<vector<char>> matrix(numRows, vector<char>(size, '0'));
        int cnt = 0;
        int column = 0;
        while(cnt<size){
        for(int i = 0 ; i<numRows ; i++){
           if(cnt<size) matrix[i][column] = s[cnt++];
        }
        column++;
        int temp_rows = numRows-1;
        while(temp_rows>1 && cnt<size){
            temp_rows--;
            matrix[temp_rows][column] = s[cnt++];
            column++;
          }
        }
        string ans = "";
        for(int i = 0 ; i<numRows;i++){
          for(int j = 0 ; j<size ; j++){
            if(matrix[i][j] != '0') ans+=(matrix[i][j]);
        }
    }
        return ans;
    }
};