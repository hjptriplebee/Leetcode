/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode* dfs(UndirectedGraphNode* now, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& mp)
    {
        if(mp.find(now) != mp.end()) return mp[now];
        UndirectedGraphNode* clone = new UndirectedGraphNode(now->label);
        mp[now] = clone;
        for(int i=0;i < now->neighbors.size(); i++)
        {
            UndirectedGraphNode* t = dfs(now->neighbors[i],mp);
            if(t) clone->neighbors.push_back(t);
        }
        return clone;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
        return dfs(node, mp);
    }
};