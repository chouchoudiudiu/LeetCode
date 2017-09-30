class Solution {
public:
    string UNDER20[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string TENS[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string THOUSAND[3] = {"Thousand", "Million", "Billion"};
    
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";//the only appearance of zero
        int i = 0;
        string words = helper(num%1000);
        while (num > 0) {
            num /= 1000;
            words = num%1000 ? helper(num%1000) + " " + THOUSAND[i] + " " + words : words;
            ++i;
        }
        if(words.back() == ' ') //dont' forget
            words.pop_back();
        return words;
    }
    
    string helper(int num) {// a number less than 1000
        if (num == 0)
            return "";
        else if (num < 20)
            return UNDER20[num];
        else if (num < 100)
            return TENS[num/10] + ( num%10 ? " " + helper(num%10) : "");
        else //num < 1000
            return UNDER20[num/100] + (num%100 ?  " Hundred " + helper(num%100) : " Hundred");
    }
};
//1000
