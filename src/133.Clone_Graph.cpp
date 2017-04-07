/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public: //BFS
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)  return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m; //to store <src, copy>
        queue<UndirectedGraphNode *> q;
        UndirectedGraphNode * nodeCopy = new UndirectedGraphNode(node->label);
        m[node] = nodeCopy;
        q.push(node);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (auto v : curr->neighbors) {
                if (m.find(v) == m.end()) {//not visited
                    UndirectedGraphNode * vCopy = new UndirectedGraphNode(v->label);
                    m[v] = vCopy;
                    q.push(v); //add to the queue!
                }
                m[curr]->neighbors.push_back(m[v]); //->neighbors
            }
        }
        
        return nodeCopy;
    }
};
