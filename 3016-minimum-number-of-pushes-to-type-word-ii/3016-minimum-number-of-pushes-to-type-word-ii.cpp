class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(char ch : word){
            freq[ch - 'a']++;
        }

        priority_queue<int> pq;
        for(int i = 0 ; i<freq.size() ; i++){
           if(freq[i]) pq.push(freq[i]);
        }

        int cnt = 0;
        int i = 0;
        while(!pq.empty()){
        cnt += (i/8 + 1)*(pq.top());
        pq.pop();
        i++;
        }
        return cnt;
    }
};