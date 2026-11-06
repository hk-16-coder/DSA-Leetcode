class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int maxi = 0;

        for(int i = 0 ; i<n ; i++){
            unordered_set<char> st;
            for(char c : words[i]){
                st.insert(c);
            }
            for(int j = i+1 ; j<n;  j++){
                bool flag = true;
                for(char c : words[j]){
                    if(st.find(c) != st.end()){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    int len = words[i].size() * words[j].size();
                    maxi = max(maxi , len );
                }
            }
        }

        return maxi;
    }
};