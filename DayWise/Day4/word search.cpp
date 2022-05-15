//https://leetcode.com/problems/word-search/submissions/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(search(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool search(vector<vector<char>>& board, string& word, int x, int y, int index) {
        if(index == word.size()) return true;
        
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size()) {
            return false;
        }
        if(board[x][y] != word[index]) {
            return false;
        }
        board[x][y] = '*';
        
        bool fsearch = search(board, word, x-1, y, index+1) || search(board, word, x+1, y, index+1) || search(board, word, x, y-1, index+1) || search(board, word, x, y+1, index+1);
        board[x][y] = word[index];
        return fsearch;
        
    }
};
