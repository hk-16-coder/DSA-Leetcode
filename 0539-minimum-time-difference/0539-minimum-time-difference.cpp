class Solution {
public:
    int time(string s){
        return ((s[0] - '0')*10 + (s[1] - '0'))*60 + ((s[3] - '0')*10 + (s[4] - '0'));
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for(string s : timePoints){
            minutes.push_back(time(s));
        }

        sort(minutes.begin() , minutes.end());

        int mini = 1e5;
        for(int i = 0 ; i<minutes.size() - 1 ; i++){
            mini= min(mini , minutes[i+1] - minutes[i]);
        }

        int diff = abs(minutes[0] + 1440 - minutes[minutes.size() - 1]);

        return min(mini,diff);
    }
};