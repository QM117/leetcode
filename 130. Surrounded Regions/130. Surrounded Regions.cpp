#include <iostream>
#include <vector>

class Solution {
private:
    int M;
    int N;
    vector<vector<int>> whitelist;
    vector<vector<int>> templist;
public:
    void solve(vector<vector<char>>& board) {
        M = board.size();
        N = board[0].size();        
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                if (!(check(board, i, j))){
                    fill(board);
                }
            }
        }
        return;
    }
    bool check(vector<vector<char>>& board, int i, int j){
        if (i < 0 || j < 0 || i >= M || j >= N){
            add_whitelist();
            return true;
        }      
        
        if (board[i][j] == 'x') return false;
        else if (check_whitelist(i, j)){
            add_whitelist();
            return true;
        }
        else if (check_templist(i, j)) return false;
        else
        {
            vector<int> x;
            x.push_back(i);
            x.push_back(j);
            templist.push_back(x);
            if (check(board, i + 1, j) || check(board, i, j + 1) || check(board, i - 1, j) || check(board, i, j - 1)) return true;
            else return false;
        }
    }
    bool check_whitelist(int i, int j){
        int L = whitelist.size();
        for (int ii = 0; ii < L; ii++)
            if (whitelist[ii][0] == i && whitelist[ii][1] == j) return true;
        return false;
    }
    void add_whitelist(){
        for (int ii = 0; ii < templist.size(); ii++) whitelist.push_back(templist[ii]);
        templist.clear();
    }
    bool check_templist(int i, int j){
        int L = templist.size();
        for (int ii = 0; ii < L; ii++)
            if (templist[ii][0] == i && templist[ii][1] == j) return true;
        return false;
    }
    void fill(vector<vector<char>>& board){
        int L = templist.size();
        for (int ii = 0; ii < L; ii++)
            board[templist[ii][0]][templist[ii][1]] == 'x';
        templist.clear();
    }
};

void main()
{
	vector<char> x;
	for (int i = 0; i < 4; i++)
		x[i] = 'x';
	cout << x[0];
}