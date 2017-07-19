class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end())
            return {}; //already in the dict
        queue<vector<string>> q; //path
        unordered_set<string> visited;
        q.push({beginWord});
        vector<vector<string>> res;
        int level = 0;
        while(!q.empty()) {
            vector<string> path = q.front();
            q.pop();
            if (path.size() > level) { //start a new level
               for (auto w:visited)
                   dict.erase(w);//these words will not be visited in next levels
               visited.clear();
               level = path.size();
            }
            string last = path.back();
            for(int i = 0; i < last.length(); ++i) { //每一个字母尝试改动
                string newWord = last;
                for(char c = 'a'; c <= 'z'; ++c) {
                    newWord[i] = c;
                    if(newWord != last && dict.find(newWord) != dict.end()) {
                        vector<string> newPath = path;
                        newPath.push_back(newWord);
                        visited.insert(newWord);
                        if(newWord == endWord) 
                            res.push_back(newPath);
                        else
                            q.push({newPath});
                    }                       
                }
            }
        }
        return res;
    }
};

           //next word is in wordList
                    //append this word to path
                    //path will be reused in the loop
                    //so copy a new path
        //"visited" records all the visited nodes on this level
        //these words will never be visited again after this level 
        //and should be removed from wordList. This is guaranteed
        // by the shortest path.
