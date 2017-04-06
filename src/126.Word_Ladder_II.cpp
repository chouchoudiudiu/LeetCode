class Solution {
public:
//bfs
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> dict(wordList.begin(), wordList.end());
       if (dict.find(endWord) == dict.end())
           return {};
       queue<vector<string>> q;
       unordered_set<string> visited;
       vector<vector<string>> res;
       q.push({beginWord});
       int level = 0, minLevel = INT_MAX; //need minlevel?
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
           for (int i = 0; i < last.length(); ++i) {
               string newWord = last;
               for (char c= 'a'; c <= 'z'; ++c) {
                   newWord[i] = c;
                   if (dict.find(newWord) != dict.end()) {//check visited?, shouldn't check, int the same level, okay
                       vector<string> newPath = path;
                       newPath.push_back(newWord);
                       visited.insert(newWord);
                       if (newWord == endWord) {
                           minLevel = level;
                           res.push_back(newPath);
                       }
                       else {
                           q.push(newPath);
                       }
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
