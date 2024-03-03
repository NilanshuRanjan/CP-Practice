class Solution {
public:
    bool searching (vector<vector<char>>& board, int row, int col, int i, string word, int n, int m){
        if (i == word.size()) return true;
        else if (row == n || row<0 || col<0 || col == m || board[row][col] != word[i]) return false;

        char ch = board[row][col];
        board[row][col] = '%';
        bool a1 = searching(board, row+1, col, i+1, word, n, m);
        if (a1) return true;
        bool a2 = searching(board, row-1, col, i+1, word, n, m);
        if (a2) return true;
        bool a3 = searching(board, row, col+1, i+1, word, n, m);
        if (a3) return true;
        bool a4 = searching(board, row, col-1, i+1, word, n, m);
        if (a4) return true;
        board[row][col] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size(); 
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                if (searching(board, i, j, 0, word, n, m)) return true;
            }
        }
        return false;    
    }
};
