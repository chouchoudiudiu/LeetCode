class TrieNode {
public:
    string word;
    TrieNode* child[26];
    TrieNode() {
        word = "";
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    };
};

class Solution {
public:
    void insert(string word) {
	TrieNode* node = root;
	for (auto c : word) {
		if (node->child[c - 'a'] == NULL)
			node->child[c - 'a'] = new TrieNode();
			node = node->child[c - 'a'];
		}
		node->word = word; //not isword
	}
	void dfs(vector<vector<char>>& board, vector<string>& words, int i, int j, int m, int n, TrieNode* node, vector<string>& res) {
	    char ch = board[i][j];
	    node = node->child[ch - 'a'];
	    if(node == NULL) //stop early if the current candidate does not exist in all words' prefix 
	        return;
	    if(node->word != "") {
	        res.push_back(node->word);
	        node->word = "";//avoid repeated add it to result
	    }
	    board[i][j] = '#';
	    if(i - 1 >= 0 && board[i - 1][j] != '#')
	        dfs(board, words, i - 1, j, m, n, node, res);
	    if(i + 1 < m && board[i + 1][j] != '#')
	        dfs(board, words, i + 1, j, m, n, node, res);
	    if(j - 1 >= 0 && board[i][j - 1] != '#')
	        dfs(board, words, i, j - 1, m, n, node, res);
	    if(j + 1 < n && board[i][j + 1] != '#')
	        dfs(board, words, i, j + 1, m, n, node, res);
	    board[i][j] = ch;
	}
	
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(board.empty() || words.empty())
            return res;
        int m = board.size(), n = board[0].size();
        root = new TrieNode();
        for(auto w : words) 
            insert(w);
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                dfs(board, words, i, j, m, n, root, res);
        return res;
    }
    
    TrieNode* root;
};
//TLE
/*
["ab","cd"]
["ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb"]

["a"]
["a","a"]
*/
