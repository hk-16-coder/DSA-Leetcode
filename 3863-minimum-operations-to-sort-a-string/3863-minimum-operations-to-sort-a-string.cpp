class Solution {
public:
    int minOperations(string s) {
        int mini_idx = -1;
        int maxi_idx = -1;
        int n = s.size();

        int maxi = -1 , mini = 30;
        bool flag = true;

        for(int i = 0 ; i<n ; i++){
            int val = s[i] - 'a';
            if(val >= maxi){
                maxi = val;
                maxi_idx = i;
            }

            if(val < mini){
                mini = val;
                mini_idx = i;
            }

            if(i>0){
                if((s[i-1] - 'a') > (s[i] - 'a')) flag = false;
            } 
        }
          
        if(flag) return 0;
        if(n == 2) return -1;
        if(mini_idx == 0 || maxi_idx == n-1) return 1;
        if(mini_idx == n-1 && maxi_idx == 0) return 3;
        return 2;
    }
};