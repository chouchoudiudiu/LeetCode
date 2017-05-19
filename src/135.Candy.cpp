class Solution {
public: //greedy
    int candy(vector<int>& ratings) {
        if (ratings.empty())
            return 0;
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
        for (int i = n - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i])
                candies[i - 1] = max(candies[i - 1], candies[i] + 1); //if less
        }
        int minCount = 0;
        for (auto v : candies)
            minCount += v;
        return minCount;
    }
};

/*
首先初始化每个人一个糖果，然后这个算法需要遍历两遍，第一遍从左向右遍历，如果右边的小盆友的等级高，等级高的小朋友加一个糖果，这样保证了一个方向上高等级的糖果多。然后再从右向左遍历一遍，如果相邻两个左边的等级高，而左边的糖果又少的话，则左边糖果数为右边糖果数加一。
*/
