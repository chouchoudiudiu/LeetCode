class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(long2short.find(longUrl) != long2short.end())
            return long2short[longUrl];
        long tmp = id;
        string s = "";
        while(tmp) {
            s += dict[tmp%62];
            tmp /= 62;
        }
        while(s.size() < 6)
            s += '0';
        long2short[longUrl] = s;
        id2long[id] = longUrl;
        ++id;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        long tmp = 0;
        for(int i = 0; i < shortUrl.size(); ++i) {
            tmp += tmp*62 + dict.find(shortUrl[i]);
        }
        return id2long.count(tmp) ? id2long[tmp] : "";
    }
    
    long id = 0;
    unordered_map<string, string> long2short;
    unordered_map<long, string> id2long; //recover long id, recvoer long url
    string dict = "0123456789abcedfghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
