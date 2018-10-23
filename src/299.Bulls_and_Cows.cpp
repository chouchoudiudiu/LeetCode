class Solution {
public:
    string getHint(string secret, string guess) {
        int nums1[10] = {0};
        int nums2[10] = {0};
        int bull = 0, cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i])
                ++bull;
            else {
                ++nums1[secret[i] - '0'];
                ++nums2[guess[i] - '0'];
            }
        }
        for (int i = 0; i < 10; ++i) {
            cows += min(nums1[i], nums2[i]); //min
        }
        return to_string(bull) + 'A' + to_string(cows) + 'B';
    }
};

///////////
class Solution {
public:
    string getHint(string secret, string guess) {
        int nums1[10] = {0};
        int nums2[10] = {0};
        for(auto s : secret) 
            nums1[s - '0']++;
        for(auto g : guess)
            nums2[g - '0']++;
        int bulls = 0, cows = 0;
        for(int i = 0; i < secret.size(); ++i) {
            if(secret[i] == guess[i])
                ++bulls;
        }
        for(int i = 0; i < 10; ++i)
            cows += min(nums1[i], nums2[i]);
        cows = cows - bulls;
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
