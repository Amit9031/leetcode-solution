class Solution {
public:
    void solve(int r, int c, vector<vector<int>>& maze, vector<vector<int>>& vis,
               string path, vector<string>& ans, int n) {

        if (r == n - 1 && c == n - 1) {
            ans.push_back(path);
            return;
        }

        // Down
        if (r + 1 < n && maze[r + 1][c] == 1 && !vis[r + 1][c]) {
            vis[r][c] = 1;
            solve(r + 1, c, maze, vis, path + 'D', ans, n);
            vis[r][c] = 0;
        }

        // Left
        if (c - 1 >= 0 && maze[r][c - 1] == 1 && !vis[r][c - 1]) {
            vis[r][c] = 1;
            solve(r, c - 1, maze, vis, path + 'L', ans, n);
            vis[r][c] = 0;
        }

        // Right
        if (c + 1 < n && maze[r][c + 1] == 1 && !vis[r][c + 1]) {
            vis[r][c] = 1;
            solve(r, c + 1, maze, vis, path + 'R', ans, n);
            vis[r][c] = 0;
        }

        // Up
        if (r - 1 >= 0 && maze[r - 1][c] == 1 && !vis[r - 1][c]) {
            vis[r][c] = 1;
            solve(r - 1, c, maze, vis, path + 'U', ans, n);
            vis[r][c] = 0;
        }
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        solve(0, 0, maze, vis, "", ans, n);

        return ans;
    }
};