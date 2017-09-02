class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m; //or freq[26]
        priority_queue<pair<int, char>> pq;
        int len = tasks.size(), idle = 0, taskN = tasks.size();
        for(auto c : tasks)
            ++m[c];
        for(auto v : m)
            pq.push({v.second, v.first}); //freq
        while(!pq.empty()) {
            vector<pair<int, char>> usable;
            int cycle = n + 1;
            for(int i = 0; i < cycle; ++i) {
                if(!pq.empty()) {
                    auto t = pq.top();
                    pq.pop();
                    if(--len == 0)
                        return taskN + idle;
                    if(--t.first > 0)
                        usable.push_back({t.first, t.second});
                }
                else
                    ++idle;
            }
            for(auto v : usable)
                pq.push(v);
        }
        return taskN + idle;
    }
};

//358. Rearrange String k Distance Apart
/*
The idea is:
To work on the same task again, CPU has to wait for time n, therefore we can think of as if there is a cycle, of time n+1, regardless whether you schedule some other task in the cycle or not.
To avoid leave the CPU with limited choice of tasks and having to sit there cooling down frequently at the end, it is critical the keep the diversity of the task pool for as long as possible.
In order to do that, we should try to schedule the CPU to always try round robin between the most popular tasks at any time.
priority_queue<task, count>
*/
