class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> mpp;
        for(int i = 0 ; i<text.size();i++){
           if(text[i] == 'b' || text[i] == 'a' || text[i] == 'l' || text[i] == 'o' || text[i] == 'n') mpp[text[i]]+=1 ;
        }
        int mini = min({mpp['b'] , mpp['a'] , mpp['l']/2 , mpp['o']/2 , mpp['n']});
        return mini;

    }
};