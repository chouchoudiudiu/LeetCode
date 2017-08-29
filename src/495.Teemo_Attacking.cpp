class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        long long total = 0;
        for (int i = 0; i < timeSeries.size(); ++i) {
            if (i > 0 && timeSeries[i] - timeSeries[i - 1] < duration)
                total += timeSeries[i] - timeSeries[i - 1];
            else
                total += duration;
        }
        return total;
    }
};


class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty())
            return 0;
        long long total = duration; //last one
        for(int i = 1; i < timeSeries.size(); ++i) {
            if(timeSeries[i] - timeSeries[i - 1] < duration)
                total += timeSeries[i] - timeSeries[i - 1];
            else 
                total += duration;
        }
        return total; 
    }
};
