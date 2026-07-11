class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Create an array of first and last occurence of each letter then simply merge intervals 
        vector<vector<int>> arr;
        unordered_map<char,pair<int,int>> occurence;

        for(int i = 0 ; i<s.size() ; i++){
            char c = s[i];
            if(occurence.find(c) != occurence.end()){
                occurence[c].second = i;
            }
            else occurence[c] = {i,i};
        }
        for(auto it  : occurence){
            arr.push_back({it.second.first , it.second.second});
        }

        // solve merge intervals for arr
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int start = arr[0][0];
        int end = arr[0][1];
        for(int i = 1 ; i<arr.size() ; i++){
            if(end>=arr[i][0]){
                end = max(end,arr[i][1]);
            }
            else{
                ans.push_back({start,end});
                start = arr[i][0];
                end = arr[i][1];
            }
        } 
        ans.push_back({start,end});
        vector<int> count;
        for(int i = 0 ; i<ans.size() ; i++){
            count.push_back(ans[i][1] - ans[i][0] + 1);
        }
        return count;
    }
};