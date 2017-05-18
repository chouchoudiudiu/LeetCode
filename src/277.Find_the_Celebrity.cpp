// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int celebrity = 0;
        for (int i = 1; i < n; ++i) {
            if (!knows(i, celebrity))
                celebrity = i;//不会hide真正的名人，因为名人只有一个，名人不认识他，他会被取代，唯一可能的
        }
        for (int i = 0; i < n; ++i) {
            if (i == celebrity)//skip self
                continue;
            if (knows(celebrity, i) || !knows(i, celebrity))
                return -1;
        }
        return celebrity;
    }
};
