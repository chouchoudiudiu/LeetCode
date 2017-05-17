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

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
		delete root;
	}
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (auto c : word) {
            if (node->child[c - 'a'] == NULL) //not exist
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* t = searchNode(word);
        return t && t->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchNode(prefix);// ? true : false;
    }
    
    TrieNode* searchNode(string prefix) {
        TrieNode* node = root;
        for (auto c : prefix) {
            if (node->child[c - 'a'])
                node = node->child[c - 'a'];
            else
                return NULL;
        }
        return node;
    }
    
    TrieNode* root;
};
/*
字典树主要有如下三点性质：
1. 根节点不包含字符，除根节点意外每个节点只包含一个字符。
2. 从根节点到某一个节点，路径上经过的字符连接起来，为该节点对应的字符串。
3. 每个节点的所有子节点包含的字符串不相同。
*/
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
