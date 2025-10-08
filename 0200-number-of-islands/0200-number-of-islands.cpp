//bfs
class Solution {
    #define pi pair<int,int>
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n , vector<bool>(m , false));

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0; j<m ;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    bfs(grid , visited , i , j);
                }
            }
        }

        return count;
    }

    void bfs(vector<vector<char>>& grid , vector<vector<bool>> &visited , int i , int j){
        int n = grid.size();
        int m = grid[0].size();

        queue<pi> q;
        q.push({i , j});
        vector<int> dir = {0 , 1 , 0 , -1 , 0};

        while(!q.empty()){
            pi curr = q.front();
            int x = curr.first;
            int y = curr.second;
            visited[x][y] = true;
            q.pop();

            for(int i=0 ;i <dir.size()-1 ; i++){
                int nx  = x + dir[i];
                int ny  = y + dir[i+1];
                if(isvalid(nx , ny , n , m ) && !visited[nx][ny] && grid[nx][ny] == '1'){
                    q.push({nx , ny});
                    visited[nx][ny] = true;
                }
            }

        }

    }

    bool isvalid(int x, int y , int n , int m){
        return (x>=0 && y>=0 && x<n && y<m);
    }


};