class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        if (denominator == 0) throw invalid_argument("denominator cant be 0");
        long long num = llabs(numerator);
        long long denom = llabs(denominator);
        bool neg = false;
        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0))
            neg = true;
        string ipart = (neg ? "-" : "") + to_string(num/denom);
        if (num%denom == 0) //== 0
            return ipart;
        string fpart = computeFpart(num%denom, denom); //num%denom
        return ipart + '.' + fpart;
    }
    
    string computeFpart(long long num, long long denom) { //num is smaller than denom
        string s;
        unordered_map<int, int> m; 
        int pos = 0;
        while (num > 0) {
            if (m.find(num) == m.end()) { 
                m[num] = pos;
                s += '0' + (num*10)/denom;
            }       
            else { //find!
                s += ')';
                s.insert(m[num], "("); //""
                break; //break!
            }
            pos++;
            num = (num*10)%denom;//yushu
        }
        return s;
    }
};
