class Solution {
private:
    bool isValid(vector<vector<char> > & board, int row, int col, char c){
        for(int i=0; i<9; i++){
            if(board[i][col] == c)
                return false;

            if(board[row][i] == c)
                return false;

            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& sudoku){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(sudoku[i][j] == '.'){
                    for(char k='1'; k<='9'; k++){
                        if(isValid(sudoku, i, j, k)){
                            sudoku[i][j] = k;
                            if(solve(sudoku))
                                return true;
                            else
                                sudoku[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};