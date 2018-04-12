class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int a = 0; a < 3; a++){
            for(int b = 0; b < 3; b++) {
                if(!ValidBlock(board, a * 3 + 1, b * 3 + 1)) return false;
                //cout<<"!"<<endl;
            }
        }
        int H = 9;
        int W = 9;

        bool FLAG_self = false;
        for(int a = 0; a < H; a++){
            for(int b = 0; b < W; b++) {
                FLAG_self = false;
                for(int c = 0; c < H; c++){
                    if(board[a][b] == '.') continue;
                    if(board[a][b] == board[c][b] && !FLAG_self) FLAG_self = true;
                    else if(board[a][b] == board[c][b] && FLAG_self) return false;   
                }
                FLAG_self = false;
                for(int c = 0; c < W; c++){
                    if(board[a][b] == '.') continue;
                    if(board[a][b] == board[a][c] && !FLAG_self) FLAG_self = true;
                    else if(board[a][b] == board[a][c] && FLAG_self) return false; 
                }
                FLAG_self = false;
            }
        }
        return true;
    }
    bool ValidBlock(vector<vector<char>>& board, int i, int j) {
        for(int a = -1; a < 2; a++){
            for(int b = -1; b < 2; b++) {
                if(board[i + a][j + b] - '.' == 0) continue;
                if(!compareblock(board, i, j, board[i + a][j + b])) return false;
            }
        }
        return true;
    }
    bool compareblock(vector<vector<char>>& board, int i, int j, char x) {
        bool flag_self = false;
        for(int a = -1; a < 2; a++){
            for(int b = -1; b < 2; b++) {
                if(x - board[i + a][j + b] == 0 && !flag_self) flag_self = true;
                else if(x - board[i + a][j + b] == 0 && flag_self) return false;                   
            }
        }
        return true;            
    }
};