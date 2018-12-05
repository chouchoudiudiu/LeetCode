class Solution {
public:
    int compareVersion(string version1, string version2) {
        replace(version1.begin(), version1.end(), '.', ' ');
        replace(version2.begin(), version2.end(), '.', ' ');
        istringstream iss1(version1), iss2(version2); //or istringstream
        while (true) {
            int n1, n2;
            bool e1 = (bool)(iss1 >> n1); //cast
            bool e2 = (bool)(iss2 >> n2);
            if (!e1 && !e2) //finished
                return 0;
            if (!e1)
                n1 = 0; //n1 = 0! not return -1
            if (!e2)
                n2 = 0; //n2 = 0!
            if (n1 > n2)
                return 1;
            if (n1 < n2)
                return -1; //if equal keep going
        }
        return 0;
    }
};
/*
n1 = 0! not return -1
"1.0"
"1"
*/
