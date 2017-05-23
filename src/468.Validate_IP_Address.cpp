class Solution {
public:
    string validIPAddress(string IP) {
        stringstream ss(IP);
        string field = "";
        int cnt = 0;
        if (IP.find('.') != string::npos) { //check IPv4
            while (getline(ss, field, '.')) {
                cnt++;
                if (cnt > 4 || field.empty() || field.size() > 3 || (field.size() > 1 && field[0] == '0'))  //0-255, no leading zeros
                    return "Neither";
                for (auto c : field) {
                    if (c < '0' || c > '9')
                        return "Neither";
                }
                int val = stoi(field);
                if (val < 0 || val > 255) 
                    return "Neither";
            }
            return (cnt == 4 && IP.back() != '.') ? "IPv4" : "Neither";
        }
        else if (IP.find(':') != string::npos) { //check IPv6
            while (getline(ss, field, ':')) {
                cnt++;
                if (cnt > 8 || field.empty() || field.size() > 4)
                    return "Neither";
                for (char c : field) { //bad input
                    if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F'))
                        return "Neither";
                }
            }
            return (cnt == 8 && IP.back() != ':') ? "IPv6" : "Neither";
        }
        else 
            return "Neither";
    }
}; //"0201:0db8:85a3:0000:0000:8a2e:0370:7334:"       "256.256.256.256"
