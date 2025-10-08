class Solution {
public:
    bool dfs(int i,int col,vector<int>&colour,vector<vector<int>>&graph){
        colour[i]=col;
        for(auto it:graph[i]){
            if(colour[it]==-1){
                if(dfs(it,!col,colour,graph)==false) return false;
            } else if(colour[it]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> colour(V,-1);
        for(int i=0;i<V;i++)colour[i]=-1;
        for(int i=0;i<V;i++){
            if(colour[i]==-1){
                if(dfs(i,0,colour,graph)==false) return false;
            }
        }
        return true;
    }
};