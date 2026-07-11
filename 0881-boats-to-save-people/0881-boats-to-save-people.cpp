class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        int n = people.size();
        sort(people.begin(),people.end());
        int right = n-1;
        int left = 0;
        
        while(left<=right){
            if(left == right){
                boats++;
                break;
            }

            else if(people[left]+people[right] > limit){
                right--;
                boats++;
            }
            
            else{
                right--; 
                left++;
                boats++;
            }
        }
        return boats;
    }
};