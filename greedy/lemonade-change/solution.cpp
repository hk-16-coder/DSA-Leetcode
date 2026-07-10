class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> notes(2,0) ; // we'll count only the notes of 5 and 10 we have

        for(int i = 0 ; i<bills.size(); i++){
            if(bills[i] == 5) notes[0]++;
            else if(bills[i] == 10){
                notes[1]++;
                if(notes[0]>0){
                    notes[0]-=1;
                }
                else return false;
            }
            else{
                if(notes[0]>0 && notes[1]>0){
                    notes[0]-=1;
                    notes[1]-=1;
                }
                else if(notes[0]>2 && notes[1] == 0){
                    notes[0]-=3;
                }
                else return false;
            }
        }
        return true;
    }
};