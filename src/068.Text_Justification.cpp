class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0;
        while (i < words.size()) {
            int j = i, len = 0;
            while (j < words.size() && len + words[j].size() + j - i <= maxWidth) //j - i is the minimum space
                len += words[j++].length();
            int spaces = maxWidth - len;
            string s; //output line
            for (int k = i; k < j; ++k) {//j is the index after the last index in this line
                s += words[k];
                int cnt = j - k - 1; //number of group of spaces to be sperated
                if (spaces > 0) { //adding spaces from left to right
                    int num = 0; //number of spaces to be filled after word[k]
                    if (j == words.size()) {//last line, special process
                        num = (cnt == 0) ? spaces : 1; // last word done if cnt == 0, otherwise always 0s       
                    }
                    else { 
                        if (cnt > 0) 
                            num = (spaces % cnt == 0) ? (spaces/cnt) : (spaces/cnt + 1); //left gets 1 more space
                        else
                            num = spaces; //last word, take all left spaces
                    }
                    s.append(num, ' ');
                    spaces -= num;
                }
            }
            res.push_back(s);
            i = j;//a new line starts
        }
        return res;
    }
};
//
/*
["a"]
1*/
//"" 0
//missed the last line
