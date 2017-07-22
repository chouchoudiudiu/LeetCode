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
