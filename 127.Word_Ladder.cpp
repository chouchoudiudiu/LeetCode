class Solution {
public:
//BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_map<string, int> m; //目前序列长度
       unordered_set<string> dict(wordList.begin(), wordList.end());
       if (dict.find(endWord) == dict.end())
           return 0;
       queue<string> q;
       m[beginWord] = 1;
       q.push(beginWord);
       while (!q.empty()) {
           string word = q.front();
           q.pop();
           for (int i = 0; i < word.length(); ++i) {
               string newWord = word;
               for (int j = 0; j < 26; ++j) {
                   newWord[i] = j + 'a';
                   if (newWord == endWord)//endWord should be in the dict too!
                       return m[word] + 1;
                   if (dict.find(newWord) != dict.end() && m.find(newWord) == m.end()) { //not visited before
                       q.push(newWord);
                       m[newWord] = m[word] + 1;
                   }
               }
           }
       }
       return 0;
    }
};
