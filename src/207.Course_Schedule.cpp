class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        for (auto v : prerequisites) {
            indegree[v.first]++; //has rely on others
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++cnt; //increment
            for (auto v : prerequisites) {
                if (v.second == u) {
                    if (--indegree[v.first] == 0)
                        q.push(v.first);
                }
            }
        }
        return cnt == numCourses;
    }
};

/*
1. Store each vertex’s In-Degree in an array D
2. Initialize queue with all “in-degree=0” vertices
3. While there are vertices remaining in the
queue:
(a) Dequeue and output a vertex
(b) Reduce In-Degree of all vertices adjacent to it by 1
(c) Enqueue any of these vertices whose In-Degree
became zero
4. If all vertices are output then success,
otherwise there is a cycle.
*/
