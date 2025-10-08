class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis)) return true;
            } else if(pathVis[it]) return true;//cycle
        }
        pathVis[node]=0;
        return false;
        
    }
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
    //using topo+bfs
    // vector<vector<int>> adj(V);
    // vector<int> indegree(V,0);
    // for(auto& pre: prerequisites){
    //     adj[pre[1]].push_back(pre[0]);
    //     indegree[pre[0]]++;
    // }
    // queue<int>q;
    // for(int i=0;i<V;i++){
    //     if(indegree[i]==0) q.push(i);
    // }
    // int cnt=0;
    // while(!q.empty()){
    //     int node=q.front();
    //     q.pop();
    //     cnt++;
    //     for(int neigh:adj[node]){
    //         indegree[neigh]--;
    //         if(indegree[neigh]==0) q.push(neigh);
    //     }
    // }
    // return cnt==V;
    
    vector<int>vis(V,0),pathVis(V,0);
    vector<vector<int>>adj(V);
    for(auto &pre:prerequisites){
        adj[pre[1]].push_back(pre[0]);
    }
    
    
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathVis)) return false;
        }
    }
    return true;

}

};