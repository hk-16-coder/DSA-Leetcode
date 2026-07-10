class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        string ans = "";
        int len = s.size();
        for(int i = 0 ; i<len ; i++) freq[s[i]] ++;
    
        priority_queue<pair<int,char>> pq;

        for(auto it : freq) pq.push({it.second,it.first});
        
        while(!pq.empty()){
           for(int i = 0 ; i<pq.top().first ; i++) ans+=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};