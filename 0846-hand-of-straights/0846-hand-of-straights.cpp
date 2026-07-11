class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;
        
        unordered_map<int,int> freq;
        for(int val : hand){
            freq[val]++;
        }
        priority_queue<int , vector<int> , greater<int>> pq;
        for(auto it : freq){
            if(it.second) pq.push(it.first);
        }

        while(!pq.empty()){
            int mini = pq.top();
            for(int i = mini ; i<mini+groupSize ; i++){
                if(freq[i] == 0) return false;
                freq[i]-=1;
                if(freq[i] == 0){
                    if(i != pq.top()) return false;
                    pq.pop();
                }
            }
        }
        return true;
    }
};