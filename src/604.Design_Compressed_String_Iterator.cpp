class StringIterator {
public:
    StringIterator(string compressedString) {
        istringstream iss(compressedString);
        int cnt = 0;
        char c = ' ';
        while(iss >> c >> cnt)
            q.push({c, cnt});
    }
    
    char next() {
        if(hasNext()) {
            auto& t = q.front();
            if(--t.second == 0)
                q.pop();
            return t.first;
        }
        return ' ';
    }
    
    bool hasNext() {
        return !q.empty();
    }
private:
    
    queue<pair<char, int>> q;
};
/*
Choose auto x when you want to work with copies.
Choose auto &x when you want to work with original items and may modify them.
Choose auto const &x when you want to work with original items and will not modify them.
*/
/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
