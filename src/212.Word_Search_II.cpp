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
		TrieNode *node = root;
		for (auto c : word)
		{
			if (node->child[c - 'a'] == NULL)
				node->child[c - 'a'] = new TrieNode();
			node = node->child[c - 'a'];
		}
		node->word = word; 
	}
    
    void dfs(vector<vector<char>>& board, int i, int j, int R, int C, TrieNode* node, vector<string>& result) 
    {
        char ch = board[i][j];
        node = node -> child[ch - 'a'];
        if (node == NULL) return; //stop early if the current candidate does not exist in all words' prefix 
        board[i][j] = '#';
        if(node->word != "")
        {
            result.push_back(node->word);
            node->word = "";
        }
        
        if (i - 1 >= 0 && board[i - 1][j] != '#') dfs(board, i - 1, j, R, C, node, result); //'#' - it has been used, can't be used again!
        if (i + 1  < R && board[i + 1][j] != '#') dfs(board, i + 1, j, R, C, node, result);
        if (j - 1 >= 0 && board[i][j - 1] != '#') dfs(board, i, j - 1, R, C, node, result);
        if (j + 1  < C && board[i][j + 1] != '#') dfs(board, i, j + 1, R, C, node, result);
        
        board[i][j] = ch; //restore
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int R = board.size();
        if (R == 0) return {};
        int C = board[0].size();
        vector<string> result;
        root = new TrieNode();
        for(auto s:words)
            insert(s);
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                dfs(board, i, j, R, C, root, result);
        return result;
    }
    
private:
    TrieNode* root;

};
//TLE
/*
["ab","cd"]
["ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb"]

["a"]
["a","a"]
*/
