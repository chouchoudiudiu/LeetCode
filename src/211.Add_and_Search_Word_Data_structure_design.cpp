class TrieNode {
public:
    TrieNode* child[26];
    bool isWord;
    
    TrieNode () {
        for (int i = 0; i < 26; ++i)
            child[i] = NULL;
        isWord = false;
    }
    ~TrieNode() {
		for (int i = 0; i < 26; i++)
			delete child[i];
	}
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    ~WordDictionary() {
        delete root;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) { //same as original trie
        TrieNode *node = root;
		for (auto c : word)
		{
			if (node->child[c - 'a'] == NULL)
				node->child[c - 'a'] = new TrieNode();
			node = node->child[c - 'a'];
		}
		node->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_recur(word, root, 0);
    }
    
    bool search_recur(string word, TrieNode* node, int start) {
        if(!node)
            return false;
        if (start == word.length())
            return node->isWord;
        if (word[start] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->child[i] && search_recur(word, node->child[i], start + 1))
                    return true;
            }
            return false; //if none of the child works
        }
        while (start < word.length() && word[start] != '.' && node) { //match as far as possible, until it reaches another '.' or end
            node = node->child[word[start] - 'a'];
            ++start;
        }
        return search_recur(word, node, start);
    }
    
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
