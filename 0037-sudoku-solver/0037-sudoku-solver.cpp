class Solution {
public:
    vector<vector<char>> ans;
    void recursive(vector<vector<char>>& board, vector<int>& rows, vector<int> &cols,  vector<vector<int>> &grids, int i, int j){

        // Base Case
        if(i == board.size()){
            ans = board;
            return;
        }

        if(board[i][j] != '.') recursive(board, rows, cols, grids, j==board[0].size()-1? i+1: i, j==board[0].size()-1? 0: j+1);
        else{
            for(int num=1; num<=9; num++){
                int mask = (1 << num);
                if(  
                    !(rows[i] & mask) && 
                    !(cols[j] & mask) && 
                    !(grids[i/3][j/3] & mask) 
                ){
                    board[i][j] = '0' + num; 
                    rows[i] ^= mask;
                    cols[j] ^= mask;
                    grids[i/3][j/3] ^= mask;
                  
                    recursive(board, rows, cols, grids, j==board[0].size()-1? i+1: i, j==board[0].size()-1? 0: j+1);
                    
rows[i] ^= mask;
                    cols[j] ^= mask;
                    grids[i/3][j/3] ^= mask;
                    board[i][j] = '.';
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<int> rows(9,0);
        vector<int> cols(9,0);
        vector<vector<int>> grids(3, vector<int>(3,0));

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] != '.'){
                    int num = int(board[i][j] - 48);
                    rows[i] |= (1 << num);
                    cols[j] |= (1 <<num);
                    grids[i/3][j/3] |= (1 << num);
                }
            }
        }

        recursive(board, rows, cols, grids, 0, 0);
        board = ans;
        
    }
};