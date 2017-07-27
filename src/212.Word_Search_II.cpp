class TrieNode {
public:
    TrieNode* child[26];
    string word;
    TrieNode() {
        word = "";
        for(int i = 0; i < 26; ++i) {
            child[i] = NULL;
        }
    }
};
class Solution {
public:
    void insert(string word) {
        TrieNode* node = root;
        for(auto c : word) {
            if(node->child[c - 'a'] == NULL) 
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        node->word = word;
    }
    void helper(vector<vector<char>>& board,  int i, int j, int m, int n, TrieNode* node, vector<string>& res) {
        char ch = board[i][j];
        node = node->child[ch - 'a'];
        if(node == NULL)//stop early if the current candidate does not exist in all words' prefix 
            return;
        if(node->word != "") {// a valid word found!
            res.push_back(node->word);
            node->word = "";//only insert once
        }
        board[i][j] = '#';
        if(i - 1 >= 0 && board[i - 1][j] != '#')
	        helper(board, i - 1, j, m, n, node, res);
	    if(i + 1 < m && board[i + 1][j] != '#')
	        helper(board, i + 1, j, m, n, node, res);
	    if(j - 1 >= 0 && board[i][j - 1] != '#')
	        helper(board, i, j - 1, m, n, node, res);
	    if(j + 1 < n && board[i][j + 1] != '#')
	        helper(board, i, j + 1, m, n, node, res);
        board[i][j] = ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || words.empty())
            return {};
        vector<string> res;
        root = new TrieNode();
        for(auto w : words)
            insert(w);
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                helper(board, i, j , m, n, root, res);
            }
        return res;
    }
    TrieNode* root;
};
