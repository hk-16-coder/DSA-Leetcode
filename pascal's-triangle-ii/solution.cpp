class Solution {
public:
int nCr(int n , int r){
            if(r==0 || r==n) return 1;
            if(r==1 || r==n-1) return n;
            long long num = 1;
            
                 for(int i = n ; i>r ; i--){
                    num = num*i/(n-i+1);
                 }
                 return num;
        }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i = 0 ; i<=rowIndex ; i++){
            ans.push_back(nCr(rowIndex,i));
        }
        return ans;
    }
};