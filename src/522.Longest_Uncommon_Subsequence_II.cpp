bool comp(pair<string, int>& p1, pair<string, int>& p2) {
    return p1.first.size() > p2.first.size();
}
bool issubstr(string s1, string s2) {
    int i = 0;
    for(auto c : s2) {
        if(c == s1[i])
            ++i;
        if(i == s1.size())
            break;
    }
    return i == s1.size();
}
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> m; //str, freq
        for(auto s : strs) 
            ++m[s];
        vector<pair<string, int>> vec;
        for(auto v : m) 
            vec.push_back(v);
        sort(vec.begin(), vec.end(), comp);
        for(int i = 0; i < vec.size(); ++i) {
            if(vec[i].second == 1) {
                int j = 0;
                for(; j < i; ++j) {
                    if(issubstr(vec[i].first, vec[j].first)) //i is shorter than j
                        break;
                }
                if(j == i) 
                    return vec[i].first.size(); 
            }
        }  
        return -1;
    }
};

//1.count每个字符串出现的次数
//2.对于只出现一次的字符串，按照长度从大到小排，该串？（整串）依次遍历是不是其他字符串(比它长)的subseq
//3.它一定不会是后面比它短的字符串的subseq，它比后面的长，所以只要考虑前面的就可以；找到第一个就可以
