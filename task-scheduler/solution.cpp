class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i = 0 ; i<tasks.size() ; i++){
            freq[tasks[i] - 'A']++;
        }

        priority_queue<int> pq;
        int cnt = 0;
        for(int i = 0 ; i<freq.size() ; i++){
            if(freq[i]>0) pq.push(freq[i]);
        }
        
        while(!pq.empty()){
            // we use the most frequent element
            vector<int> temp;
            for(int i = 0 ; i<=n ; i++){
                // we need a gap of n so total time is n+1
               if(!pq.empty()){ 
                int max_freq = pq.top();
                pq.pop();
                max_freq--;
                temp.push_back(max_freq);
                }
            }

            // now we add freq back to the heap
            for(int i = 0 ; i<temp.size() ; i++){
                if(temp[i]>0) pq.push(temp[i]);
            }

            if(!pq.empty()){
                cnt+=n+1;
            }
            else cnt+=temp.size();
        }
        return cnt;
    }
};