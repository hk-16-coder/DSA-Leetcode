class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        long long start = 0 , end = 0;
        start = start + startTime[7] + 10*startTime[6] + 60*(startTime[4] + 10*startTime[3]) + 60*60*(startTime[1] + 10*startTime[0]);

        end = end + endTime[7] + 10*endTime[6] + 60*(endTime[4] + 10*endTime[3]) + 60*60*(endTime[1] + 10*endTime[0]);

        return (int)(end - start);
    }
};