class Solution {
public:
    int dist(vector<int>& p1 , vector<int>& p2){
        return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int,int> mpp;
        mpp[dist(p1,p2)]++;
        mpp[dist(p1,p3)]++;
        mpp[dist(p1,p4)]++;
        mpp[dist(p2,p3)]++;
        mpp[dist(p2,p4)]++;
        mpp[dist(p3,p4)]++;

        if(mpp.size() != 2) return false;
        auto it = mpp.begin();
        int key1 = it->first;
        it++;
        int key2 = it->first;

        if(key1*2 != key2 && key2*2 != key1) return false;
       
        return true;
    }
};