class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        queue<pair<pair<int,int>, int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int fresh=0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int count=q.front().second;

            q.pop();
            ans=count;

            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1){
                q.push({{i-1,j},count+1});
                fresh--;
                vis[i-1][j]=1;
            }
             if(i+1<n && !vis[i+1][j] && grid[i+1][j]==1){
                q.push({{i+1,j},count+1});
                fresh--;
                vis[i+1][j]=1;
            }
             if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==1){
                q.push({{i,j-1},count+1});
                fresh--;
                vis[i][j-1]=1;
            }
             if(j+1<m && !vis[i][j+1] && grid[i][j+1]==1){
                q.push({{i,j+1},count+1});
                fresh--;
                vis[i][j+1]=1;
            }
        }
        return (fresh==0)?ans:-1;
    }
};