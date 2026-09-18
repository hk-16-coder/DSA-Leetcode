class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int,int>> occ(26 , {-1,-1});
        int n = s.size();
        
        for(int i = 0 ; i<n ; i++){
            int c = s[i] - 'a';
            if(occ[c].first == -1 && occ[c].second == -1){
                occ[c] = {i,i};
            }
            else{
                occ[c].second = i;
            }
        }
        vector<pair<int,int>> arr;

        for(int i = 0 ; i<26 ; i++){
            if(occ[i].first == -1) continue;

            int l = occ[i].first;
            int r = occ[i].second;
            bool flag = true;

            for(int j = l ; j<=r ; j++){
                int x = s[j] - 'a';
                if(occ[x].first < l){
                    flag = false;
                    break;
                }
                r = max(r , occ[x].second);
            }
            if(flag) arr.push_back({l,r});
        }
        
       sort(arr.begin() , arr.end() , [](pair<int,int> p1 , pair<int,int> p2){
        return p1.second < p2.second;
       });
       
       vector<string> ans;
       int last = -1;
       for(auto it : arr){
           int l = it.first;
           int r = it.second;

           if(l > last){
            ans.push_back(s.substr(l , r-l+1));
            last = r;
         }
       }

       return ans;
    }
};