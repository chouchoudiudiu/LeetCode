class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(long2short.find(longUrl) != long2short.end())
            return long2short[longUrl];
        string s;
        long tmp = id;
        while(id) {
            s += dict[tmp%62];
            tmp /=  62;
        }
        while(s.size() < 6) {
            s = '0' + s;
        }
        long2short[longUrl] = s; 
        id2long[id] = longUrl;
        id++;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        long num = 0;
        for(int i = 0; i < shortUrl.size(); ++i) {
            num = num*62 + dict.find(shortUrl[i]);
        }
        return id2long.count(num) ? id2long[num] :"";
    }
    
    unordered_map<string, string> long2short;
    unordered_map<long, string> id2long;
    //recover long id, recover long url
    string dict = "0123456789abcedfghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    long id = 0;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
