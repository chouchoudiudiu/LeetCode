class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        int N = A.size();
        int freq[N][26] = {0};
        for(int i = 0; i < N; ++i) {
        	for(auto c : A[i]) 
        		freq[i][c - 'a']++;
        }
        for(int i = 0; i < 26; ++i) {
        	int minCount = N;
            bool found = true;
        	for(int j = 0; j < N; ++j) {
        		if(freq[j][i] == 0) {
                    found = false; //do we really need this
        			break; 
                }
                minCount = min(minCount, freq[j][i]);
        	}
            if(found) {
        	    for(int cnt = 0; cnt < minCount; ++cnt)
        	    	res.push_back(string(1, i + 'a')); //from char to string
            }
        }
        return res;
    }
};
