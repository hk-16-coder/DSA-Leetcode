class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q = queries.size();
        vector<int> ans(q);

        sort(logs.begin() , logs.end() , [](vector<int>& a , vector<int>& b){
            return a[1] < b[1];
        });

        vector<pair<int,int>> arr(q);
        for(int i = 0 ; i<q ; i++){
            arr.push_back({queries[i] , i});
        }

        sort(arr.begin() , arr.end());
        int L = logs.size();
        int l = 0 , r = 0;

        unordered_map<int,int> freq;
        int active = 0;

        for(auto& it : arr){
            int time = it.first;
            int idx = it.second;
            
            while(r < L && logs[r][1] <= time){
                int s = logs[r][0];
                freq[s]++;
                if(freq[s] == 1) active++;
                r++;
            }

            while(l < r && logs[l][1] < time - x){
                int s = logs[l][0];
                freq[s]--;
                if(freq[s] == 0) active--;
                l++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};