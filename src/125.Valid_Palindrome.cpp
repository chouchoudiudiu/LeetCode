class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        for(int l = 0, r = s.size() - 1; l < r; ++l, --r){
            while(l < r && !isalnum(s[l]))
                ++l;
            while(l < r && !isalnum(s[r]))
                --r;
            if(l < r) {
                if(toupper(s[l]) != toupper(s[r])) 
                    return false;
            }
        }
        return true;
    }
};

======
    class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while(l < r) {
            while(l < r && !isalnum(s[l]))
                ++l;
            while(l < r && !isalnum(s[r]))
                --r;
            if(l > r)
                return true;
            if(tolower(s[l++]) != tolower(s[r--]))
                return false;
        }
        return true;
    }
};
