class Solution {
public:
/*Greedy: whenever encounter ‘*’ in p, keep record of the current position of ‘*’ in p and the current index in s.
Try to match the stuff behind this ‘*’ in p with s, if not matched, just s++ and then try to match again.
https://simpleandstupid.com/category/leetcode/*/
    bool isMatch(string s, string p) {        
        int i = 0; 
        int j = 0;
        int starPos = -1; 
        int posInS = -1;      
        while ( i < s.length() )  {
            if ( j < p.length() && (s[i] == p[j] || p[j] == '?') ) {
                i++;
                j++;
            }
            else if ( j < p.length() && (p[j] == '*')) { //remember the last time it meets the *, of course matches are 
                //satisifed before 
                starPos = j;
                j++; 
                posInS = i;
            }
            else if ( starPos != -1 ) {//important step! restart the search!
                j = starPos + 1;
                i = ++posInS; //s keeps moving forward
            }
            else {
                return false;
            }
        }   
        //extra * in the end, but s is done
        while ( j < p.length() && p[j] == '*')
            ++j;

        return j == p.length();    
    }
};
/*
"aabcdefgtaghc"
"a*ghc"
*/
/*
"aa"
"*"
*/
