class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //bool res = false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(backtrack(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }
    
    bool backtrack(vector<vector<char>> &board, int i, int j, int pos, const string &word){
        if(pos == word.size()) 
            return true;
        
        //if(pos >= word.size()) return false;
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[pos])
            return false;
        
        char temp = board[i][j];
        // backtrack part 1
        board[i][j] = '*';
        // backtrack part 2
        bool res = backtrack(board, i - 1, j, pos + 1, word) ||
                   backtrack(board, i, j - 1, pos + 1, word) ||
                   backtrack(board, i + 1, j, pos + 1, word) ||
                   backtrack(board, i, j + 1, pos + 1, word);
        // backtrack part 3
        board[i][j] = temp;
        return res;
    }
};