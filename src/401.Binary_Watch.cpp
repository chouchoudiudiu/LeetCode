class Solution {
public:
//using bitset
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0; h < 12; ++h)
            for (int m = 0; m < 60; ++m) {
                if (bitset<10>(h << 6 | m).count() == num) //共10位，hour左移6位，与minute拼接后count set的总位数
                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m)); 
            }
            return res;
    }
};
