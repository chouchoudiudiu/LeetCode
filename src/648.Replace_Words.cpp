//reconstruct the dict, when you find a shorter one to it, replace it?
//sort the dict vector, when constructing the hashtable, check what's behind it
//okay i feel trie works best

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> m(dict.begin(), dict.end());
        stringstream ss(sentence);
        string res, token;
        while(getline(ss, token, ' ')) {
            string prefix = "";
            for(int i = 0; i < token.length(); ++i) {
                prefix += token[i]; //easier than substr
                if(m.find(prefix) != m.end()) 
                    break;
            }
            res += prefix + " ";
        }
        res.pop_back();
        return res;
    }
};

//no need to build trie
