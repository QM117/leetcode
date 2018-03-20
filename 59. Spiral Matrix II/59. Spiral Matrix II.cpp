class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //n++;
        vector<vector<int>> Matrix(n, vector<int>(n,0));
        if(n == 0) return Matrix;
        //cout<< Matrix.size() << " " << Matrix[0].size();
        int i = 0, j = 0, x = 1;
        for(int u = 1; u <= (n+1)/2; u++){
            //cout<<i<<" "<<j<<" "<<Matrix[i][j]<<endl;
            if(Matrix[i][j] == 0) Matrix[i][j] = x++;
            while(j + 1 < n && Matrix[i][j+1] == 0) Matrix[i][++j] = x++;
            while(i + 1 < n && Matrix[i+1][j] == 0) Matrix[++i][j] = x++;
            while(j - 1 >= 0 && Matrix[i][j-1] == 0) Matrix[i][--j] = x++;
            //cout<<i<<" "<<j<<" "<<Matrix[i][j]<<endl;
            while(i - 1 >= 0 && Matrix[i-1][j] == 0) Matrix[--i][j] = x++;
            j++;
        }
        return Matrix;
    }
};
//题不难 主要是找到赋值的规律 分成一圈一次循环的赋值即可 这里主要是 初始化为0矩阵耗时过大 2为别人利用边界条件做的