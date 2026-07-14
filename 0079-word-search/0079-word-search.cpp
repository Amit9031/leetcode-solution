class Solution {
public:
    bool dfs(vector<vector<char>> &mat, vector<vector<bool>> &vis,
             string &word, int i, int j, int idx) {

        int n = mat.size();
        int m = mat[0].size();

        if (idx == word.size())
            return true;

        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;

        if (vis[i][j] || mat[i][j] != word[idx])
            return false;

        vis[i][j] = true;

        bool found = dfs(mat, vis, word, i + 1, j, idx + 1) ||
                     dfs(mat, vis, word, i - 1, j, idx + 1) ||
                     dfs(mat, vis, word, i, j + 1, idx + 1) ||
                     dfs(mat, vis, word, i, j - 1, idx + 1);

        vis[i][j] = false;   // Backtracking

        return found;
    }

    bool exist(vector<vector<char>> &mat, string &word) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(mat, vis, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};