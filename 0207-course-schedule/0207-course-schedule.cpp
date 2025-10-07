class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(V);     
    vector<int> indegree(V, 0);     

    for (auto& pre : prerequisites) {
        adj[pre[1]].push_back(pre[0]);
        indegree[pre[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int neigh : adj[node]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0) q.push(neigh);
        }
    }

    return count == V;
}

};