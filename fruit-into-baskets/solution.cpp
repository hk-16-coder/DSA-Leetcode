class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int right = 0;
        unordered_map<int,int> freq;
        int max_fruit = 0;
        while(right<n){
            freq[fruits[right]]++;
            right++;
            if(freq.size()>2) {
               freq[fruits[left]]--;
               if(freq[fruits[left]] == 0) freq.erase(fruits[left]);
                left++;
            }
           
            max_fruit = max(max_fruit,right-left);
        }
        return max_fruit;
    }
};