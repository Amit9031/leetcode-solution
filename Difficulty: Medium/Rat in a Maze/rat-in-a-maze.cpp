class Solution {
public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        int n = maze.size();
        vector<string> ans;
        
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;
        
        queue<pair<pair<int, int>, pair<string, vector<vector<int>>>>> q;
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        
        q.push({{0, 0}, {"", visited}});
        
        while (!q.empty()) {
            
            int i = q.front().first.first;
            int j = q.front().first.second;
            
            string s = q.front().second.first;
            vector<vector<int>> vis = q.front().second.second;
            
            q.pop();
            
            if (i == n - 1 && j == n - 1) {
                ans.push_back(s);
                continue;
            }
            
            // Down
            if (i + 1 < n && maze[i + 1][j] == 1 &&
                vis[i + 1][j] == 0) {
                
                vector<vector<int>> newVis = vis;
                newVis[i + 1][j] = 1;
                
                q.push({{i + 1, j}, {s + 'D', newVis}});
            }
            
            // Up
            if (i - 1 >= 0 && maze[i - 1][j] == 1 &&
                vis[i - 1][j] == 0) {
                
                vector<vector<int>> newVis = vis;
                newVis[i - 1][j] = 1;
                
                q.push({{i - 1, j}, {s + 'U', newVis}});
            }
            
            // Right
            if (j + 1 < n && maze[i][j + 1] == 1 &&
                vis[i][j + 1] == 0) {
                
                vector<vector<int>> newVis = vis;
                newVis[i][j + 1] = 1;
                
                q.push({{i, j + 1}, {s + 'R', newVis}});
            }
            
            // Left
            if (j - 1 >= 0 && maze[i][j - 1] == 1 &&
                vis[i][j - 1] == 0) {
                
                vector<vector<int>> newVis = vis;
                newVis[i][j - 1] = 1;
                
                q.push({{i, j - 1}, {s + 'L', newVis}});
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};