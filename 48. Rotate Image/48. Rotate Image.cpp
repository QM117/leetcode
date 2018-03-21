class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int n = matrix.size();
        if(n == 1) return;
        int i = 0, j = 0, u = 0;
        for(u = 0; u <int (n/2.0+1/2.0); u++){
            j = u;
            for(i = u; i < n - 1 - u; i++) swap(matrix,i,j,n);
            for(j = u; j < n - 1 - u; j++) swap(matrix,i,j,n);
            for(i = n - 1 - u; i > u; i--) swap(matrix,i,j,n);
        }
    }
    void swap(vector<vector<int>>& matrix, int i, int j, int n) {
        int x = matrix[i][j];
        matrix[i][j] = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = x;
        //cout<<i<<" "<<j<<endl;
    }
};
//3次循环逆时针	2是顺时针 一次循环