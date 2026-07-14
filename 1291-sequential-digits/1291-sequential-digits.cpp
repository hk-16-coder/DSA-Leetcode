class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;

        for(int len = 2 ; len<10 ; len++){
              for(int i = 0 ; i<10-len ; i++){
                int num  = stoi(s.substr(i,len));
                if(num>=low && num<=high) ans.push_back(num);
              }
        }
        return ans;
    }
};