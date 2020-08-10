// Rotten Oranges

#define f first
#define s second
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({0, {i, j}});
                }
            }
        }
        
        int time = 0;
        
        while(!q.empty()) {
            pair<int, pair<int, int>> p = q.front();
            q.pop();
            int x = p.s.f;
            int y = p.s.s;
            time = max(time, p.f);
            
            if(x && grid[x - 1][y] == 1) {
                q.push({p.f + 1, {x - 1, y}});
                grid[x - 1][y] = 2;
            }
            
            if(y && grid[x][y - 1] == 1) {
                q.push({p.f + 1, {x, y - 1}});
                grid[x][y - 1] = 2;
            }
            
            if(x < m - 1 && grid[x + 1][y] == 1) {
                q.push({p.f + 1, {x + 1, y}});
                grid[x + 1][y] = 2;
            }
            
            if(y < n - 1 && grid[x][y + 1] == 1) {
                q.push({p.f + 1, {x, y + 1}});
                grid[x][y + 1] = 2;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return time;
    }
};