class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        long long cnt = 1LL*(2*n);
        unordered_map<int,vector<int>> rows;

        for(auto &it : reservedSeats){
            int row = it[0];
            int col = it[1];
            if(col>=2 && col<=9){
                rows[row].push_back(col);
            }
        }
        
        for(auto &it : rows){
            int row = it.first;
            vector<int>seats = it.second;

            bool left = true , middle = true , right = true;
            for(int col : seats){
                if(col>=2 && col<=5) left = false;
                if(col>=4 && col<=7) middle = false;
                if(col>=6 && col<=9) right = false;
            }

            cnt-=2;
            if(left && right) cnt+=2;
            else if(left || middle || right) cnt+=1;
        }
        return cnt;
    }
};