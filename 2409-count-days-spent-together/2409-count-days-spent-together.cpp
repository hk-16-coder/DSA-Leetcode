class Solution {
public:
    int f(string s){
        int month = (s[0] - '0')* 10 + (s[1] - '0');
        int days = (s[3] - '0') * 10 + (s[4] - '0');

        map<int,int> mpp = {{1,31} ,{2,28} , {3,31} , {4,30} , {5,31} , {6,30} , {7,31} , {8,31} , {9,30}, {10,31} , {11,30} , {12,31}};

        for(int i = 1 ; i<month ; i++){
            days += mpp[i];
        }

        return days;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int overlap = min(f(leaveAlice) , f(leaveBob)) - max(f(arriveAlice) , f(arriveBob));
        if(overlap < 0) return 0;
        return  overlap + 1;
    }
};