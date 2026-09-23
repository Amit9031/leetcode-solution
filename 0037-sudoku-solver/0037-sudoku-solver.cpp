class Solution {
public:
bool safe(vector<vector<char>>&board, int row, int col, char val){
    for(int i=0;i<9;i++){
        if(board[row][i]==val)return false;
    }
    for(int j=0;j<9;j++){
        if(board[j][col]==val)return false;
    }
    int startr=row-row%3;
    int startc=col-col%3;
    for(int i=startr;i<startr+3;i++){
        for(int j=startc;j<startc+3;j++){
            if(board[i][j]==val)return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>&board){

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char k='1'; k<='9';k++){
                    if(safe(board, i, j,k)){
                        board[i][j]=k;
                        if(solve(board))
                        return true;
                    
                    board[i][j]='.';
                }}
                return false;
            }
        }}
        return true;
    
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};