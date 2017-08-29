class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        for(int i = 0; i < flowerbed.size() && cnt < n; ++i) {
            if(flowerbed[i] == 0) {
                int prev = i == 0 ? 0 : flowerbed[i - 1]; 
                int next = i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1];
                if(prev == 0 && next == 0) {
                    flowerbed[i] = 1;
                    ++cnt;
                }
            }
        }
        return cnt == n;
    }
};

//Greedily place a flower at every vacant spot encountered from left to right!
//get next and prev flower bed slot values. If i lies at the ends the next and prev are considered as 0. 

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0)
            return true;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for(int i = 1; i < flowerbed.size() - 1; ++i) {
            if(flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                --n;
                if(n == 0)
                    return true;
            }
        }
        return n == 0;
    }
};

//both left and right are 0, place 1
/*
[0,0,1,0,0]
1

[0,0,0,0,0,1,0,0]
0
*/
